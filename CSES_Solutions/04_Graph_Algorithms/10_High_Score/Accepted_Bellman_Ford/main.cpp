#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<vector<array<ll, 2>>> adj(n+1);
    vector<vector<ll>> adj2(n+1);
    vector<ll> dist(n+1, -INF);
    vector<bool> vis(n+1, 0), vis2(n+1, 0);
    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
        adj2[b].push_back(a);
    }
    
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        for(int c: adj2[u]){
            if(!vis[c])
                dfs(c);
        }
    };
    function<void(int)> dfs2 = [&](int u){
        vis2[u] = 1;
        for(array<ll, 2> c: adj[u]){
            if(!vis2[c[1]])
                dfs2(c[1]);
        }
    };
    
    dfs(n);
    dfs2(1);
    dist[1] = 0;
    for(int i = 1; i <= n; i++){
        bool ch = 0;
        for(int j = 1; j <= n; j++){
            for(array<ll, 2> a: adj[j]){
                if(dist[j] + a[0] > dist[a[1]]){
                    if(vis[a[1]] && vis2[a[1]])
                        ch = 1;
                    dist[a[1]] = dist[j] + a[0];
                }
            }
        }
        if(i == n && ch){
            cout<<"-1\n";
            return 0;
        }
    }
    
    cout<<dist[n];
    return 0;
}