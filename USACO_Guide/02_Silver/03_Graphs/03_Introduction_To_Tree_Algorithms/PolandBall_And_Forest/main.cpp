#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    vector<int> vis(n+1);
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        for(int c: adj[u]){
            if(!vis[c]){
                dfs(c);
            }
        }
    };
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout<<ans<<"\n";
}
