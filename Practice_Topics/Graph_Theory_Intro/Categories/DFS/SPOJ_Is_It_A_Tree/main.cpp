#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://www.spoj.com/problems/PT07Y/

vector<ll> adj[100001];
int visited[100001];

void dfs(int node){
    visited[node] = 1;
    
    for(int child: adj[node]){
        if(!visited[child])
            dfs(child);
    }
}

int main(){
    ll n, m, a, b;
    scanf("%lld%lld", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%lld%lld", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll count = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            count++;
        }
    }
    
    if(count == 1 && m == n-1)
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}