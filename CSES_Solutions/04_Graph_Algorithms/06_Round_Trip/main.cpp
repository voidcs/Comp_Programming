#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    vector<bool> vis(n+1, 0);
    vector<int> last(n+1, -1);
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    function<void(int, int)> dfs = [&](int u, int par){
        vis[u] = 1;
        for(int c: adj[u]){
            if(!vis[c]){
                last[c] = u;
                dfs(c, u);
            }
            else{
                if(c != par){
                    vector<int> ans;
                    int curr = u;
                    ans.push_back(u);
                    while(curr != c){
                        ans.push_back(last[curr]);
                        curr = last[curr];
                    }
                    ans.push_back(u);
                    cout<<ans.size()<<endl;
                    for(auto x: ans)
                        cout<<x<<" ";
                    cout<<endl;
                    exit(0);
                }
            }
        }
    };
    
    for(int i = 1; i <= n; i++){
        if(!vis[i])
            dfs(i, -1);
    }
    cout<<"IMPOSSIBLE\n";
    
    return 0;
}