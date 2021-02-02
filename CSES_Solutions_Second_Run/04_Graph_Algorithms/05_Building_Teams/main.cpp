#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1, 0);
    vector<int> color(n+1, -1);
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool flag = 0;
    function<void(int, int)> dfs = [&](int u, int col){
        vis[u] = 1;
        color[u] = col;
        for(int c: adj[u]){
            if(!vis[c]){
                vis[c] = 1;
                dfs(c, col^1);
            }
            else{
                if(color[c] == color[u]){
                    flag = 1;
                    break;
                }
            }
        }
    };
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, 0);
        }
    }
    if(flag){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        for(int i = 1; i <= n; i++)
            cout<<color[i]+1<<" ";
        cout<<endl;
    }
    
    
    return 0;
}