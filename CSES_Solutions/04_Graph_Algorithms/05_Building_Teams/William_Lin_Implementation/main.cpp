#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    vector<int> color(n+1, -1);
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    function<void(int, int)> dfs = [&](int node, int col){
        if(~color[node]){
            if(col != color[node]){
                cout<<"IMPOSSIBLE\n";
                exit(0);
            }
            return;
        }
        color[node] = col;
        for(int c: adj[node])
            dfs(c, col^1);
    };

    for(int i = 1; i <= n; i++){
        if(color[i] == -1)
            dfs(i, 0);
    }
    
    for(int i = 1; i <= n; i++)
        cout<<color[i]+1<<" ";
    cout<<endl;

    return 0;
}