#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//PROBLEM LINK
//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/social-networking-graph/
//Reference video
//https://www.youtube.com/watch?v=kppa3JOAj6A&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=21

vector<int> adj[1000001];
bool vis[1000001];
int level[1000001];
int dist[1000001];

void bfs(int node){
    queue<ll> q;
    q.push(node);
    vis[node] = 1;
    while(!q.empty()){
        ll curr = q.front();
        q.pop();
        for(int child: adj[curr]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                dist[child] = dist[curr] + 1;
                level[dist[child]]++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        ll a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    ll q;
    cin>>q;
    while(q--){
        for(int i = 0; i <= n; i++){
            level[i] = 0, vis[i] = 0, dist[i] = 0;
        }
        ll src, distance;
        cin>>src>>distance;
        bfs(src);
        cout<<level[distance]<<endl;
    }
    return 0;
}