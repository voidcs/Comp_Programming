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
    vector<int> vis(n+1);
    int ans = 0;
    function<int(int)> dfs = [&](int u){
        vis[u] = 1;
        vector<int> distances;
        for(int c: adj[u]){
            if(!vis[c])
                distances.push_back(dfs(c) + 1);
        }
        sort(distances.rbegin(), distances.rend());
        if(distances.size() == 1)
            ans = max(ans, distances[0]);
        else if(distances.size() > 1)
            ans = max(ans, distances[0] + distances[1]);
        if(distances.empty())
            return 0;
        else
            return distances[0];
    };
    dfs(1);
    cout<<ans<<"\n";
}
