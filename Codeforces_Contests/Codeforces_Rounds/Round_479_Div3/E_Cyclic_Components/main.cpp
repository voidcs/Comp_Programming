#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0, found = 0, cc = 0;
    set<array<int, 2>> s;
    vector<int> vis(n+1), last(n+1, -1);
    function<void(int, int)> dfs = [&](int u, int par){
        cc++;
        vis[u] = 1;
        for(int c: adj[u]){
            s.insert({min(u, c), max(u, c)});
            if(!vis[c]){
                vis[c] = 1;
                last[c] = u;
                dfs(c, u);
            }
            else{
                if(par != c && !found){
                    found = c;
                    last[c] = u;
                }
            }
        }
    };
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            s.clear();
            found = 0, cc = 0;
            dfs(i, -1);
            if(found){
                vector<int> cycle;
                cycle.push_back(found);
                ll curr = found;
                while(last[curr] != found){
                    cycle.push_back(last[curr]);
                    curr = last[curr];
                }
                if(cycle.size() == cc && s.size() == cc){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
