#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<array<ll, 2>> adj(n);
    for(int i = 0; i < n; i++){
        cin>>adj[i][0];
        adj[i][1] = i+1;
    }
    auto g = adj;
    sort(g.begin(), g.end());
    vector<array<ll, 3>> edges(m);
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        edges[i] = {c, a, b};
    }
    ll ans = 0;
    vector<ll> par(n+1);
    iota(par.begin(), par.end(), 0);
    function<ll(ll)> find = [&](ll x){
        return (x == par[x]) ? x : par[x] = find(par[x]);
    };
    auto unite = [&](ll x, ll y){
        x = find(x), y = find(y);
        if(x != y){
            par[x] = y;
        }
    };
    for(int i = 1; i < n; i++){
        edges.push_back({g[0][0] + g[i][0], g[0][1], g[i][1]});
    }
    sort(edges.begin(), edges.end());
//    for(auto x: edges){
//        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
//    }
    for(int i = 0; i < edges.size(); i++){
        ll x = edges[i][1];
        ll y = edges[i][2];
        ll c = edges[i][0];
        if(find(x) != find(y)){
            //cout<<"uniting: "<<x<<" "<<y<<" for cost: "<<c<<endl;
            ans += c;
            unite(x, y);
        }
    }
    cout<<ans<<endl;
    
    
    return 0;
}
