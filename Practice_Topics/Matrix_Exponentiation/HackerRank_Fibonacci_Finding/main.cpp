#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b, n;
        cin>>a>>b>>n;
        vector<vector<ll>> v(2, vector<ll>(2, 0));
        v[0][1] = v[1][1] = v[1][0] = 1;
        
        function<vector<vector<ll>>(vector<vector<ll>>, vector<vector<ll>>)> mult = [&](vector<vector<ll>> a, vector<vector<ll>> b){
            vector<vector<ll>> res(2, vector<ll>(2, 0));
            for(int i = 0; i < 2; i++)
                res[i][i] = 1;
            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    res[i][j] = 0;
                    for(int k = 0; k < 2; k++){
                        res[i][j] += (a[i][k]%mod) * (b[k][j]%mod);
                        res[i][j] %= mod;
                    }
                }
            }
            return res;
        };
        function<void(ll)> expo_pow = [&](ll power){
            vector<vector<ll>> res(2, vector<ll>(2, 0));
            for(int i = 0; i < 2; i++)
                res[i][i] = 1;
            while(power){
                if(power%2){
                    power--;
                    res = mult(res, v);
                }
                v = mult(v, v);
                power /= 2;
            }
            v = res;
        };
        expo_pow(n);
        ll ans = ((a * v[0][0])%mod) + ((b * v[1][0])%mod);
        cout<<ans%mod<<endl;
    }
    return 0;
}