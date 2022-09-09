#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1), transpose(n+1);
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        transpose[b].push_back(a);
    }
    vector<int> vis(n+1);
    vector<int> order;
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        for(int c: adj[u]){
            if(!vis[c])
                dfs(c);
        }
        order.push_back(u);
    };
    for(int i = 1; i <= n; i++){
        if(!vis[i])
            dfs(i);
    }
    vector<int> ans(n+1);
    vis = vector<int>(n+1);
    int cnt = 1;
    function<void(int)> dfs2 = [&](int u){
        vis[u] = 1;
        ans[u] = cnt;
        for(int c: transpose[u]){
            if(!vis[c])
                dfs2(c);
        }
    };
    for(int i = n-1; i >= 0; i--){
        if(!vis[order[i]]){
            dfs2(order[i]);
            cnt++;
        }
    }
    cout<<cnt-1<<"\n";
    for(int i = 1; i <= n; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
 
    return 0;
}