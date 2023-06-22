#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    sort(v.begin(), v.end());
    ll m = v[n/2];
    ll ans = 0;
    for(ll x: v){
        ans += abs(x - m);
    }
    cout<<ans<<"\n";
}