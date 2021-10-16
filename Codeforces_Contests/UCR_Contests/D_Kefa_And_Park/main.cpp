#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> cats(n+1), vis(n+1);
    for(int i = 1; i <= n; i++){
        cin>>cats[i];
    }
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans = 0;
    function<void(int, int)> dfs = [&](int u, int cnt){
        vis[u] = 1;
        if(cats[u]){
            cnt++;
        }
        if(cnt > m)
            return;
        bool isLeaf = 1;
        for(int c: adj[u]){
            if(!vis[c]){
                isLeaf = 0;
                if(cats[c])
                    dfs(c, cnt);
                else
                    dfs(c, 0);
            }
        }
        if(isLeaf && cnt <= m){
            ans++;
        }
    };
    dfs(1, 0);
    cout<<ans<<endl;
    return 0;
}
