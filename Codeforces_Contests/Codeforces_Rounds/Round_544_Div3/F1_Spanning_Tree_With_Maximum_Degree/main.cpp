#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e9;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++, deg[b]++;
    }
    int start = 0, c = 0;
    for(int i = 0; i < n; i++){
        if(deg[i] > c){
            c = deg[i], start = i;
        }
    }
    vector<bool> vis(n);
    queue<array<int, 2>> q;
    q.push({start, -1});
    while(q.size()){
        int u = q.front()[0];
        int par = q.front()[1];
        q.pop();
        if(par != -1){
            cout<<u+1<<" "<<par+1<<endl;
        }
        vis[u] = 1;
        for(int c: adj[u]){
            if(!vis[c]){
                vis[c] = 1;
                q.push({c, u});
            }
        }
    }
    
    return 0;
}