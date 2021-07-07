#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    unordered_map<ll, unordered_map<ll, ll>> m;
    for(ll x: v){
        ll t = x, add = 1;
        while(t <= (ll)1e18){
            t *= 10;
            m[add][t%k]++;
            add++;
        }
    }
    ll ans = 0;
    for(ll x: v){
        ll len = to_string(x).length();
        ll r = x%k;
        ll need = (k-r)%k;
        if(m[len].count(need))
           ans += m[len][need]; 
        ll t = x;
        for(int i = 0; i < len; i++)
            t *= 10;
        if(((t%k)+r)%k == 0)
            ans--;
    }
    cout<<ans<<endl;

    return 0;
}
