#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll m, n, k;
    cin>>n>>m>>k;
    vector<vector<array<ll, 2>>> adj(n);
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        a--, b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    set<ll> storage;
    for(int i = 0; i < k; i++){
        ll x;
        cin>>x;
        storage.insert(x-1);
    }
    queue<array<ll, 2>> q;
    vector<ll> dist(n, INF);
    for(ll x: storage){
        q.push({x, 0});
        dist[x] = 0;
    }
    ll ans = INF;
    while(q.size()){
        ll u = q.front()[0];
        ll cost = q.front()[1];
        q.pop();
        for(auto c: adj[u]){
            if(cost + c[1] < dist[c[0]]){
                dist[c[0]] = cost + c[1];
                q.push({c[0], dist[c[0]]});
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(!storage.count(i)){
            ans = min(ans, dist[i]);
        }
    }
    if(ans == INF)
        cout<<"-1\n";
    else
        cout<<ans<<endl;
    return 0;
}
