#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i = 1; i < n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    long double ans = 0;
    vector<int> vis(n+1);
    function<void(int, int, long double)> dfs = [&](int u, int path_len, long double p){
        vis[u] = 1;
        bool leaf = 1;
        int unvis = 0;
        for(int c: adj[u]){
            if(!vis[c])
                unvis++;
        }
        for(int c: adj[u]){
            if(!vis[c]){
                leaf = 0;
                dfs(c, path_len + 1, p / unvis);
            }
        }
        if(leaf){
            ans += path_len * p;
        }
    };
    dfs(1, 0, 1);
    cout<<fixed<<setprecision(8)<<ans<<"\n";
}
