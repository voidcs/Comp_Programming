#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
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
    vector<bool> vis(n+1);
    int ans = 0;
    function<int(int, int)> dfs = [&](int u, int d){
        vis[u] = 1;
        vector<int> dist;
        for(int c: adj[u]){
            if(!vis[c]){
                int x = dfs(c, 0);
                dist.push_back(x);
            }
        }
        int sum = 0;
        //cout<<"u: "<<u<<"  ";
        sort(dist.begin(), dist.end());
        reverse(dist.begin(), dist.end());
        if(dist.size()){
            sum = dist[0];
            d = max(d, dist[0]);
        }
        if(dist.size() > 1)
            sum += dist[1];
        //cout<<"  d: "<<d<<"  sum: "<<sum<<endl;
        ans = max(ans, sum);
        return d + 1;
    };
    
    dfs(1, 0);
    cout<<ans<<endl;
    return 0;
}