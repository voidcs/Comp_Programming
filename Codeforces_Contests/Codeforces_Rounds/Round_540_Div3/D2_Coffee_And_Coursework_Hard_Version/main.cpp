#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll &x: v){
        cin>>x;
    }
    sort(v.rbegin(), v.rend());
    ll ans = INF;
    ll l = 1, r = 1e18;
    while(l <= r){
        ll m = (l+r)/2;
        ll sum = 0;
        for(ll j = 0; j < n; j++){
            sum += max(0LL, v[j] - j/m);
        }
        if(sum >= k){
            ans = min(ans, m);
            r = m-1;
        }
        else
            l = m+1;
    }
    if(ans == INF)
        cout<<"-1\n";
    else
        cout<<ans<<endl;
    
    return 0;
}
