#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin>>a>>b;
        adj[b].push_back(a);
    }
    int ans = -1;
    for(int i = n; i >= 1; i--){
        vector<int> vis(n+1);
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for(int c: adj[u]){
                if(!vis[c]){
                    vis[c] = 1;
                    dfs(c);
                }
            }
        };
        dfs(i);
        bool ok = 1;
        for(int j = 1; j <= n; j++){
            ok &= vis[j];
        }
        if(ok)
            ans = i;
    }
    cout<<ans<<endl;
    return 0;
}
