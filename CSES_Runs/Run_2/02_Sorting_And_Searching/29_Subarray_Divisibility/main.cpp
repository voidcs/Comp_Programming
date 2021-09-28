#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    map<ll, ll> m;
    m[0]++;
    ll pref = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        a[i] = ((a[i]%n)+n)%n;
        pref += a[i];
        pref %= n;
        if(m.count(pref));
            ans += m[pref];
        m[pref]++;
    }
    cout<<ans<<endl;
    
    return 0;
}