#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans = 0;
    vector<int> vis(n+1);
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        int need = adj[u].size() + (u == 1);
        int x = 1;
        while(x < need){
            ans++;
            x *= 2;
        }
        for(int c: adj[u]){
            if(!vis[c]){
                ans++;
                dfs(c);
            }
        }
    };
    dfs(1);
    cout<<ans<<"\n";
}
