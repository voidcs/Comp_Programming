#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://atcoder.jp/contests/dp/tasks/dp_g

int in[1000001];
int dist[1000001];
bool vis[1000001];
vector<int> adj[1000001];

void dfs(int node){
    vis[node] = 1;
    for(int child: adj[node]){
        dist[child] = max(dist[child], dist[node] + 1);
        in[child]--;
        if(in[child] == 0)
            dfs(child);
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        in[b]++;
    }
    
    for(int i = 1; i <= n; i++){
        if(!vis[i] && in[i] == 0)
            dfs(i);
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dist[i]);
    
    printf("%d\n", ans);
    
    return 0;
}
