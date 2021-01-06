#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1296/B

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans = 0;
        while(n >= 10){
            ll extra = n%10;
            ans += n-extra;
            n = n / 10 + extra;
        }
        ans += n;
        cout<<ans<<endl;
    }
    return 0;
}