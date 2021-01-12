#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector<vector<ll>> v(n, vector<ll>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin>>v[i][j];
        
        function<vector<vector<ll>>(vector<vector<ll>>, vector<vector<ll>>)> mult = [&](vector<vector<ll>> a, vector<vector<ll>> b){
            vector<vector<ll>> res(n, vector<ll>(n, 0));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    res[i][j] = 0;
                    for(int k = 0; k < n; k++){
                        res[i][j] += (a[i][k]%mod) * (b[k][j]%mod);
                        res[i][j] %= mod;
                    }
                }
            }
            return res;
        };
        function<void(ll)> expo_pow = [&](ll power){
            vector<vector<ll>> res(n, vector<ll>(n, 0));
            for(int i = 0; i < n; i++)
                res[i][i] = 1;
            while(power){
                if(power%2){
                    power--;
                    res = mult(res, v);
                }
                power /= 2;
                v = mult(v, v);
            }
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    v[i][j] = res[i][j];
        };
        expo_pow(k);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}