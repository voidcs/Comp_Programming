#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<array<int, 2>> pos(n+1);
    for(int i = 1; i <= n; i++){
        cin>>pos[i][0]>>pos[i][1];
    }
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> vis(n+1);
    int ans = 1e9;
    int min_x = 1e9, max_x = 0, min_y = 1e9, max_y = 0;
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        min_x = min(min_x, pos[u][0]);
        max_x = max(max_x, pos[u][0]);
        min_y = min(min_y, pos[u][1]);
        max_y = max(max_y, pos[u][1]);
        for(int c: adj[u]){
            if(!vis[c])
                dfs(c);
        }
    };
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            min_x = 1e9, max_x = 0, min_y = 1e9, max_y = 0;
            dfs(i);
            ans = min(ans, 2 * (max_x - min_x) + 2 * (max_y - min_y));
        }
    }
    cout<<ans<<"\n";
} 
