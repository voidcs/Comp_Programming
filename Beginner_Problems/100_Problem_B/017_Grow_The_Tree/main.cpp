#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1248/B

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(a, a + n);
    ll x = 0, y = 0;
    for(int i = 0; i < n/2; i++)
        x += a[i];
    for(int i = n/2; i < n; i++)
        y += a[i];
    ll ans = x*x + y*y;
    cout<<ans<<endl;
    
    return 0;
}