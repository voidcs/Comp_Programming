#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/

vector<ll> adj[100001];
int visited[100001];
int dist[100001];

void dfs(int node, int d){
    visited[node] = 1;
    dist[node] = d;
    
    for(int child: adj[node]){
        if(!visited[child])
            dfs(child, d+1);
    }
}

int main(){
    ll n, q, a, b;
    scanf("%lld", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%lld%lld", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);

    ll ans = -1;
    ll min_dist = 10e10;
    scanf("%lld", &q);

    while(q--){
        ll city;
        scanf("%lld", &city);
        
        if(dist[city] < min_dist){
            min_dist = dist[city];
            ans = city;
        }
        
        else if(dist[city] == min_dist && city < ans)
            ans = city;
    }
    
    printf("%lld\n", ans);
    
    return 0;
}