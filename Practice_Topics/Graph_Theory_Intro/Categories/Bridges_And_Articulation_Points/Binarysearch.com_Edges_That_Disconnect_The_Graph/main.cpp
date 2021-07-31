//https://binarysearch.com/problems/Edges-that-Disconnect-the-Graph
int solve(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> low(n), in(n), vis(n);
    int ans = 0, timer = 0;
    function<void(int, int)> dfs = [&](int u, int par){
        vis[u] = 1;
        in[u] = low[u] = timer++;
        for(int c: adj[u]){
            if(c == par)
                continue;
            if(vis[c]){
                low[u] = min(low[u], in[c]);
            }
            else{
                vis[c] = 1;
                dfs(c, u);
                if(low[c] > in[u])
                    ans++;
                low[u] = min(low[u], low[c]);
            }
        }
    };
    dfs(0, -1);
    return ans;
}