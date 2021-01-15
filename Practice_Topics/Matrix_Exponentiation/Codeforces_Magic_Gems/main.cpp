#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
#define mat vector<vector<ll>>

//PROBLEM LINK
//https://codeforces.com/contest/1117/problem/D

int main(){
    ll n, m;
    cin>>n>>m;
    if(n < m){
        cout<<"1\n";
        return 0;
    }
    mat v(m, vector<ll>(m, 0));
    v[m-1][0] = v[m-1][m-1] = 1;
    for(int i = 0; i < m-1; i++)
        v[i][i+1] = 1;

    function<mat(mat, mat)> mult = [&](mat a, mat b){
        mat res(m, vector<ll>(m, 0));
        for(int i = 0; i < m; i++){
            for(int k = 0; k < m; k++){
                for(int j = 0; j < m; j++){
                    res[i][j] += (a[i][k] * b[k][j]);
                    res[i][j] %= mod;
                }
            }
        }
        return res;
    };
    
    function<void(ll)> expo_power = [&](ll power){
        mat res(m, vector<ll>(m, 0));
        for(int i = 0; i < m; i++)
            res[i][i] = 1;
        while(power){
            if(power%2)
                res = mult(v, res);
            v = mult(v, v);
            power /= 2;
        }
        v = res;
    };
    expo_power(n-m+1);
    ll ans = 0;
    for(int i = 0; i < m; i++){
        ans = (ans + v[m-1][i]) % mod;
    }
    cout<<ans<<endl;
    
    return 0; 
}