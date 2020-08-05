#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
//PROBLEM LINK
//https://www.hackerrank.com/challenges/fibonacci-finding-easy/problem

auto mul(vector<vector<ll>> a, vector<vector<ll>> b){
    ll n = a.size();
    vector<vector<ll>> res(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res[i][j] = 0;
            for(int k = 0; k < n; k++){
                ll x = (1LL * a[i][k] * b[k][j]) % mod;
                res[i][j] = (res[i][j] + x) % mod;
            }
        }
    }
    return res;
}

auto getFib(vector<ll> a, ll n){
    if(n <= 1){
        return a[n];
    }
    vector<vector<ll>> I(2, vector<ll>(2));
    for(int i = 0; i < 2; i++){
        I[i][i] = 1;
    }
    
    vector<vector<ll>> T(2, vector<ll>(2));
    T[0][0] = 0;
    T[0][1] = T[1][0] = T[1][1] = 1;
    
    while(n){
        if(n%2){
            I = mul(I, T);
        }
        T = mul(T, T);
        n /= 2;
    }
    
    ll ans = (a[0] * I[0][0] + a[1] * I[1][0]) % mod;
    return ans;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        vector<ll> a(2);
        ll n;
        cin>>a[0]>>a[1]>>n;
        cout<<getFib(a, n)<<endl;
    }
    return 0;
}