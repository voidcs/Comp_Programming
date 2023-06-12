#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int n, q;
    cin>>n>>q;
    vector<vector<array<int, 2>>> adj(n+1);
    for(int i = 1; i < n; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    while(q--){
        int k, x;
        cin>>k>>x;
        vector<int> vis(n+1);
        int ans = 0;
        function<void(int, int)> dfs = [&](int u, int m){
            vis[u] = 1;
            if(u != x && m >= k)
                ans++;
            for(auto [c, w]: adj[u]){
                if(!vis[c]){
                    dfs(c, min(m, w));
                }
            }
        };
        dfs(x, 2e9);
        cout<<ans<<"\n";
    }
}
