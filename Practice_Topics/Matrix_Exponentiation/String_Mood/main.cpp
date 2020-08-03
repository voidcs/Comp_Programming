#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

//PROBLEM LINK
//https://codeforces.com/gym/102644/problem/B

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

auto pow(vector<vector<ll>> a, ll n){
    vector<vector<ll>> iden(2, vector<ll>(2));
    for(int i = 0; i < 2; i++)
        iden[i][i] = 1;
    
    while(n){
        if(n%2){
            iden = mul(iden, a);
        }
        a = mul(a, a);
        n /= 2;
    }
    return iden;
}

int main(){
    ll n;
    cin>>n;
    
    vector<vector<ll>> a(2, vector<ll>(2, 0));
    a[0][0] = 19, a[0][1] = 7, a[1][0] = 6, a[1][1] = 20;
    
    vector<vector<ll>> ans = pow(a, n);
//    for(int i = 0; i < ans.size(); i++){
//        for(int j = 0; j < ans[i].size(); j++){
//            cout<<ans[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<ans[0][0]<<endl;
    return 0;
}