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
    vector<ll> sum(n+1), subtree(n+1);
    function<int(int)> dfs1 = [&](int u){
        vis[u] = 1;
        subtree[u] = 1;
        sum[u] = 0;
        for(int c: adj[u]){
            if(!vis[c]){
                ll child_subtree_size = dfs1(c);
                subtree[u] += child_subtree_size;
                sum[u] += sum[c] + subtree[c]; //Take the sum of child c, each of them get one step further so we add subtree[c] for each node
            }
        }
        return subtree[u];
    };
    dfs1(1);
    vis = vector<int>(n+1);
    vector<ll> ans(n+1);
    function<void(int, int)> dfs2 = [&](int u, int par){
        vis[u] = 1;
        if(par != -1){
            //Take the answer of everything of the parent and subtract your own subtree, this is ans[par] - sum[u]
            //We will shift all of this closer to vertex u, so we add one for each node. The total nodes is n - subtree[u]
            //Finally we need to move closer to everything already in our subtree
            //They all get one step closer and there are subtree[u] of them, so we add sum[u] - subtree[u]
            ans[u] = ans[par] - sum[u] + (n - subtree[u]) + sum[u] - subtree[u];
        }
        else{
            ans[u] = sum[u];
        }
        for(int c: adj[u]){
            if(!vis[c])
                dfs2(c, u);
        }
    };
    dfs2(1, -1);
    for(int i = 1; i <= n; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}
