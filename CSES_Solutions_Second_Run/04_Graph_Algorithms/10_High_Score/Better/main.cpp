#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    /*
     * The first n-1 iterations guarantee that all distances are maximized
     * by a property of bellman ford algorithm. If a node's distance grows
     * after our n-1 iterations, then it must be an infinite cycle 
     * or known as a negative cycle in similar problems.
     * 
     * However we only care about the path from 1 to n, therefore the infinite
     * cycle is only relevant if it is on the path from 1 to n. We perform
     * a dfs starting from node 1 and if the node whose distance increases
     * is visited by the dfs, then we can claim the distance to n is infinite
     * 
     * ALTERNATIVE SOLUTION
     * Simply ignore nodes with distance of negative infinity
     * Then they will not contribute to the end
    */
 
    ll n, m;
    cin>>n>>m;
    vector<vector<array<ll, 2>>> adj(n+1);
    while(m--){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
    }
    vector<ll> vis(n+1, 0);
    function<void(ll)> dfs = [&](ll u){
        vis[u] = 1;
        for(array<ll, 2> a: adj[u]){
            ll c = a[1];
            if(!vis[c]){
                vis[c] = 1;
                dfs(c);
            }
        }
    };
    dfs(1);
    
    vector<ll> dist(n+1, -INF);
    dist[1] = 0;
    
    for(int i = 1; i <= 2*n; i++){
        for(int j = 1; j <= n; j++){
            for(array<ll, 2> a: adj[j]){
                ll cost = a[0];
                ll u = a[1];
                if(dist[j] == -INF)
                    continue;
                if(dist[j] + cost > dist[u]){
                    dist[u] = dist[j] + cost;
                    if(i >= n){
                        dist[u] = INF;
                    }
                }
            }
        }
    }
    if(dist[n] == INF)
        cout<<"-1\n";
    else
        cout<<dist[n]<<endl;
    
    return 0;
}