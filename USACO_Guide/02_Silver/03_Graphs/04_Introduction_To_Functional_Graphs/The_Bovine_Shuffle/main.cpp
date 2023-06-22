#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    vector<vector<int>> adj(n); //Backwards adjacency list to mark non-cycle nodes as visited
    for(int i = 0; i < n; i++){
        cin>>v[i];
        v[i]--;
        adj[v[i]].push_back(i);
    }
    vector<int> vis(n);
    int ans = 0;
    function<void(int)> reverse_dfs = [&](int u){
        vis[u] = 1;
        for(int c: adj[u]){
            if(!vis[c])
                reverse_dfs(c);
        }
    };
    function<void(int)> floyd = [&](int u){
        int x = u;
        int y = u;
        do{
            x = v[x];
            y = v[v[y]];
        }while(x != y);
        //Now x and y met in the cycle
        //Mark all nodes in cycle and increment answer for each
        do{
            x = v[x];
            vis[x] = 1;
            ans++;
        }while(x != y);
        //Mark all non cycle nodes as visited
        do{
            reverse_dfs(x);
            x = v[x];
        }while(x != y);
    };
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            floyd(i);
        }
    }
    cout<<ans<<"\n";
}
