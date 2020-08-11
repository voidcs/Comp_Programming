#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
Sample case #1
6 5
1 2
2 3
2 4
4 5
4 6

Sample case #2
13 16
1 2
2 3
2 4
3 4
1 7
7 6
1 6
1 5
5 8
8 9
9 5
5 12
12 10
5 10
10 11
12 13
*/

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
                //cout<<"Node "<<node<<" is a cut vertex\n";
                cut_vertices.insert(node);
            }
            children++;
        }
    }
    if(par == -1 && children > 1){
        cut_vertices.insert(node);
        //cout<<"Node "<<node<<" is a cut vertex\n";
    }
}

int main(){
    ll n, m;
    cout<<"Enter the number of nodes and number of edges\n";
    cin>>n>>m;
    in = vector<ll> (n+1, -1);
    low = vector<ll> (n+1, -1);
    timer = 0;
    while(m--){
        ll a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++){
        vis[i] = 0;
    }
    
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, -1);
        }
    }
    
    cout<<"List of articulation points: ";
    for(auto x: cut_vertices){
        cout<<x<<" ";
    }

    return 0;
}