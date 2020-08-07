#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=rFVKXZZMH-U&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=16

vector<int> adj[100001];
bool vis[100001];
int subSize[100001];

int dfs(int node){
    vis[node] = 1;
    int size = 1;
    for(int child: adj[node]){
        if(vis[child] == 0){
            size += dfs(child);
        }
    }
    subSize[node] = size;
    return size;
}

int main(){
    int n;
    int edges;
    cout<<"Enter the number of nodes and edges: \n";
    cin>>n>>edges;
    for(int i = 0; i < edges; i++){
        int a, b;
        cout<<"Enter a pair of connected nodes: \n";
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout<<"Subtree sizes: \n";
    for(int i = 1; i <= n; i++){
        cout<<"Node: "<<i<<"  subtree size: "<<subSize[i]<<endl;
    }
    
    return 0;
}