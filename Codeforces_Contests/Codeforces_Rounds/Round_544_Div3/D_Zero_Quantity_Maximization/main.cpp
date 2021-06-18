#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n), b(n);
    for(ll &x: a)
        cin>>x;
    for(ll &x: b)
        cin>>x;
    map<array<ll, 2>, ll> m;
    ll cnt = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        //d can be anything when a[i] == 0 and b[i] == 0
        if(a[i] == 0 && b[i] == 0){
            cnt++;
            continue;
        }
        //If b[i] == 0, we choose d to be 0
        if(b[i] == 0){
            cnt2++;
            continue;
        }
        //If a[i] alone is 0, we cannot do anything with this
        if(a[i] == 0)
            continue;
        ll g = __gcd(a[i], b[i]);
        a[i] /= g, b[i] /= g;
        ll x = a[i] * b[i];
        if(x < 0){
            b[i] = abs(b[i]);
            a[i] = abs(a[i]) * -1;
        }
        m[{a[i], b[i]}]++;
    }
    ll ans = 0;
    for(auto x: m)
        ans = max(ans, x.second);
    ans = max({ans, cnt2});
    cout<<ans + cnt<<endl;
    
    return 0;
}