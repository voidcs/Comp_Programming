#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
//PROBLEM LINK
//https://codeforces.com/contest/1426/problem/C

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans = 1e15;
        for(int i = 1; i*i <= n; i++){
            ll x = (i-1) + ((n+i-1)/i) - 1;
            ans = min(ans, x);
        }
        cout<<ans<<endl;
    }
    return 0;
}