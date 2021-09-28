#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> vis(n+1, 0);
    vector<array<int, 2>> ans;
   
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        for(int c: adj[u]){
            if(!vis[c]){
                vis[c] = 1;
                dfs(c);
            }
        }
    };
    
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            if(i > 1)
                ans.push_back({1, i});
        }
    }
    cout<<ans.size()<<endl;
    for(auto x: ans)
        cout<<x[0]<<" "<<x[1]<<endl;
    return 0;
}