#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll x, n;
    cin>>x>>n;
    set<ll> pos;
    map<ll, ll> m;
    pos.insert(0);
    pos.insert(x);
    m[x] = 1;
    while(n--){
        cin>>x;
        auto it = pos.lower_bound(x);
        ll r = *it;
        it--;
        ll l = *it;
        m[r-l]--;
        if(m[r-l] == 0)
            m.erase(r-l);
        m[r-x]++;
        m[x-l]++;
        pos.insert(x);
        cout<<(--m.end())->first<<endl;
    }
    return 0;
}