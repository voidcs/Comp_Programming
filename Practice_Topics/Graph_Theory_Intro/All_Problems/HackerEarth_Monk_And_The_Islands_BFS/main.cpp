#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/

vector<int> adj[100001];
bool vis[100001];
int dist[100001];

void bfs(int node){
    queue<int> q;
    vis[node] = 1;
    q.push(node);
    dist[node] = 0;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int child: adj[curr]){
            if(!vis[child]){
                q.push(child);
                dist[child] = dist[curr] + 1;
                vis[child] = 1;
            }
        }
    }
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        
        for(int i = 0; i < m; i++){
            vis[i] = 0;
            dist[i] = 0;
            adj[i].clear();
        }
        
        for(int i = 0; i < m; i++){
            ll a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        bfs(1);
        cout<<dist[n]<<endl;
        
    }
    
    return 0;
}