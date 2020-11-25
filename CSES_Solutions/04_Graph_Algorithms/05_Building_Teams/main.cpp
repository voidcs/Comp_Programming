#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    vector<int> color(n+1, 0);
    vector<bool> vis(n+1, 0);
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    function<bool(int, int)> dfs = [&](int node, int col){
        color[node] = col;
        vis[node] = 1;
        for(int c: adj[node]){
            if(!vis[c]){
                bool res = dfs(c, col^1);
                if(!res)
                    return 0;
            }
            else{
                if(color[node] == color[c])
                    return 0;
            }
        }
        return 1;
    };
    bool flag = 1;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            flag = dfs(i, 0);
        }
        if(!flag)
            break;
    }
    if(flag){
        for(int i = 1; i <= n; i++)
            cout<<color[i]+1<<" ";
        cout<<endl;
    }
    else
        cout<<"IMPOSSIBLE\n";
    
    return 0;
}