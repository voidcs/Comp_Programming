#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
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
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = 1;
        for(int c: adj[u]){
            if(!vis[c]){
                last[c] = u;
                q.push(c);
                vis[c] = 1;
            }
        }
    }
    if(vis[n] == 1){
        int u = n;
        vector<int> ans;
        ans.push_back(n);
        while(u != 1){
            ans.push_back(last[u]);
            u = last[u];
        }
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<endl;
        for(auto x: ans)
            cout<<x<<" ";
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
    
    return 0;
}