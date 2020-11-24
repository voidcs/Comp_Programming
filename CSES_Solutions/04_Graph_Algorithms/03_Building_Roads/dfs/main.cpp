#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    vector<int> vis(n+1, 0);
    while(m--){
        ll a, b;
        cin>>a>>b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    
    function<void(int)> dfs = [&](int node){
        vis[node] = 1;
        for(int c: adj[node]){
            if(!vis[c])
                dfs(c);
        }
    };

    vector<array<ll, 2>> pairs;
    dfs(1);
    for(int i = 2; i <= n; i++){
        if(!vis[i]){
            dfs(i);
            pairs.push_back({1, i});
        }
    }
    
    cout<<pairs.size()<<endl;
    for(auto x: pairs)
        cout<<x[0]<<" "<<x[1]<<endl;
    
    return 0;
}