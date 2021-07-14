#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    map<ll, ll> m;
    for(ll &x: v){
        cin>>x;
        m[x]++;
    }
    ll ans = 0;
    for(auto x: v){
        bool ok = 0;
        m[x]--;
        for(ll i = 0; i <= 32; i++){
            ll need = (1LL<<i) - x;
            if(m.count(need) && m[need] >= 1)
                ok = 1;
        }
        if(!ok)
            ans++;
        m[x]++;
    }
    cout<<ans<<endl;
    return 0;
}
