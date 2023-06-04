#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    while(cin>>n>>m){
        if(n + m == 0)
            break;
        bool ok = 0;
        vector<vector<array<int, 2>>> adj(n);
        for(int i = 0; i < m; i++){
            int a, b;
            cin>>a>>b;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
        }
        for(int i = 0; i < m; i++){
            int cnt = 0;
            vector<int> vis(n);
            function<void(int)> dfs = [&](int u){
                vis[u] = 1;
                cnt++;
                for(auto [c, j]: adj[u]){
                    if(!vis[c] && j != i)
                        dfs(c);
                }
            };
            dfs(0);
            if(cnt != n)
                ok = 1;
        }
        if(ok)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
} 
