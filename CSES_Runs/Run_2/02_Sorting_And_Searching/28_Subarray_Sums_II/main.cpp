#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, x;
    cin>>n>>x;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    map<ll, ll> m;
    m[0]++;
    ll pref = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        pref += a[i];
        if(m.count(pref-x))
            ans += m[pref-x];
        m[pref]++;
    }
    cout<<ans<<endl;
    
    return 0;
}