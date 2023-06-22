#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1), adj2(n+1);
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    vector<int> ans;
    int not_visited = -1;
    auto vis_cnt = [&](vector<vector<int>> adj){
        int cnt = 0;
        vector<int> vis(n+1);
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            cnt++;
            for(int c: adj[u]){
                if(!vis[c])
                    dfs(c);
            }
        };
        dfs(1);
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                not_visited = i;
            }
        }
        ans.push_back(not_visited);
        return cnt;
    };
    int a = vis_cnt(adj2);
    not_visited = -1;
    int b = vis_cnt(adj);
    if(a == n && b == n)
        cout<<"YES\n";
    else{
        cout<<"NO\n";
        if(ans[1] == -1)
            cout<<ans[0]<<" 1\n";
        else
            cout<<"1 "<<ans[1]<<"\n";
    }
} 
