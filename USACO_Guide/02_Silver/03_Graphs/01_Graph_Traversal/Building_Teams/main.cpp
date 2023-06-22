#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> color(n+1, -1);
    bool ok = 1;
    function<void(int, int)> dfs = [&](int u, int col){
        color[u] = col;
        for(int c: adj[u]){
            if(color[c] == -1){
                dfs(c, col ^ 1);
            }
            else{
                if(color[c] == col){
                    ok = 0;
                }
            }
        }
    };
    for(int i = 1; i <= n; i++){
        if(color[i] == -1){
            dfs(i, 0);
        }
    }
    if(ok){
        for(int i = 1; i <= n; i++){
            cout<<color[i] + 1<<" ";
        }
        cout<<"\n";
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
} 
