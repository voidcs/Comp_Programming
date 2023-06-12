#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n+1);
    //First calculate the answer for node 1, this will also "solve" for all nodes if we don't account for the parent path
    vector<int> ans(n+1);
    vector<vector<array<int, 2>>> best(n+1);
    function<int(int)> dfs1 = [&](int u){
        vis[u] = 1;
        vector<array<int, 2>> distances;    //Also store which direction we came from
        for(int c: adj[u]){
            if(!vis[c])
                distances.push_back({dfs1(c) + 1, c});
        }
        if(distances.size()){
            sort(distances.rbegin(), distances.rend());
            for(int i = 0; i < min(2, (int)distances.size()); i++)
                best[u].push_back(distances[i]);
            ans[u] = distances[0][0];
            return ans[u];
        }
        else{
            return 0;
        }
    };
    dfs1(1);
    function<void(int, int)> dfs2 = [&](int u, int par){
        vis[u] = 1;
        if(par != -1){
            int x = 1;
            for(auto [len, path_id]: best[par]){
                if(path_id != u){
                    x = max(x, len + 1);
                }
            }
            best[u].push_back({x, par});
            for(auto [len, path_id]: best[u])
                ans[u] = max(ans[u], len);
        }
        for(int c: adj[u]){
            if(!vis[c]){
                dfs2(c, u);
            }
        }
    };
    vis = vector<int>(n+1);
    dfs2(1, -1);
    for(int i = 1; i <= n; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}