#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> closed(n+1);
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    auto check = [&](){
        int cc = 0;
        vector<int> vis(n+1);
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for(int c: adj[u]){
                if(!vis[c] && !closed[c])
                    dfs(c);
            }
        };
        for(int i = 1; i <= n; i++){
            if(!vis[i] && !closed[i]){
                cc++;
                dfs(i);
            }
        }
        if(cc == 1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    };
    check();
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        closed[x] = 1;
        if(i < n-1)
            check();
    }
} 
