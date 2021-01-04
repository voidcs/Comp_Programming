#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1399/B

int main(){
    ll t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a[n], b[n];
        ll minOrange = INF, minCandy = INF;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            minCandy = min(minCandy, a[i]);
        }
        for(int i = 0; i < n; i++){
            cin>>b[i];
            minOrange = min(minOrange, b[i]);
        }
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll x = min(a[i]-minCandy, b[i]-minOrange);
            ans += x;
            a[i] -= x;
            b[i] -= x;
            ans += a[i] - minCandy;
            ans += b[i] - minOrange;
        }
        cout<<ans<<endl;
    }
    return 0;
}