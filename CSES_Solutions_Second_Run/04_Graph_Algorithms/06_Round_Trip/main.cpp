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
    vector<int> vis(n+1, 0);
    vector<int> last(n+1, -1);
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = -1;
    function<void(int, int)> dfs = [&](int u, int par){
        vis[u] = 1;
        last[u] = par;
        for(int c: adj[u]){
            if(!vis[c]){
                vis[c] = 1;
                dfs(c, u);
            }
            else if(vis[c] && c != par){
                if(ans == -1){
                    last[c] = u;
                    ans = c;
                    break;
                }
            }
        }
    };
    
    for(int i = 1; i <= n; i++){
        if(!vis[i])
            dfs(i, -1);
    }
    if(ans == -1)
        cout<<"IMPOSSIBLE\n";
    else{
        int u = ans;
        vector<int> cycle;
        cycle.push_back(u);
        while(last[u] != ans){
            cycle.push_back(last[u]);
            u = last[u];
        }
        cycle.push_back(ans);
        cout<<cycle.size()<<endl;
        for(auto x: cycle)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}