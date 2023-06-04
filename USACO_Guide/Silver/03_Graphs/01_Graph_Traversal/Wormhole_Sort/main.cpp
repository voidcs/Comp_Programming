#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    ll n, m;
    cin>>n>>m;
    vector<ll> v(n);
    for(ll &x: v){
        cin>>x;
        x--;
    }
    vector<array<ll, 3>> edge;
    while(m--){
        ll a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        edge.push_back({a, b, c});
    }
    auto valid = [&](ll width){
        vector<ll> par(n);
        iota(par.begin(), par.end(), 0);
        function<ll(ll)> find = [&](ll x){
            return (x == par[x]) ? x : par[x] = find(par[x]);
        };
        auto unite = [&](ll x, ll y){
            x = find(x);
            y = find(y);
            if(x != y)
                par[x] = y;
        };
        for(auto [a, b, c]: edge){
            if(c >= width){
                unite(a, b);
            }
        }
        bool ok = 1;
        for(int i = 0; i < n; i++){
            if(find(i) != find(v[i]))
                ok = 0;
        }
        return ok;
    };
    ll l = 0, r = INF;
    ll ans = -1;
    while(l <= r){
        ll m = (l + r) / 2;
        if(valid(m)){
            ans = m;
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    if(ans == INF)
        cout<<"-1\n";
    else
        cout<<ans<<"\n";
} 
