#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i = 2; i <= n; i++){
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    vector<int> vis(n+1), ans(n+1);
    function<int(int)> dfs = [&](int u){
        int cnt = 1;
        vis[u] = 1;
        for(int c: adj[u]){
            if(!vis[c]){
                cnt += dfs(c);
            }
        }
        ans[u] = cnt - 1;
        return cnt;
    };
    dfs(1);
    for(int i = 1; i <= n; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
}
