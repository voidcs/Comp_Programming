#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

//PROBLEM LINK
//https://www.spoj.com/problems/SUBMERGE/
//REFERENCE VIDEO
//https://www.youtube.com/watch?v=N1dZjuR0Y88&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=27

vector<ll> adj[100001];
ll vis[100001];
vector<ll> in, low;
ll timer;
set<ll> cut_vertices;

void dfs(int node, int par){
    vis[node] = 1;
    in[node] = low[node] = timer++;
    int children = 0;
    for(int child: adj[node]){
        if(child == par){
            continue;
        }
        
        if(vis[child]){
            low[node] = min(low[node], in[child]);
        }
        else{
            dfs(child, node);
            low[node] = min(low[node], low[child]);
            if(low[child] >= in[node] && par != -1){
                cut_vertices.insert(node);
            }
            children++;
        }
    }
    if(par == -1 && children > 1){
        cut_vertices.insert(node);
    }
}

int main(){
    ll n, m;
    while(cin>>n>>m){
        if(n == 0 && m == 0)
            return 0;
        
        for(int i = 1; i <= n; i++)
            adj[i].clear(), vis[i] = 0;
        in = vector<ll> (n+1);
        low = vector<ll> (n+1);
        timer = 0;
        cut_vertices.clear();
        while(m--){
            ll a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i, -1);
            }
        }
        
        cout<<cut_vertices.size()<<endl;
    }
    return 0;
}