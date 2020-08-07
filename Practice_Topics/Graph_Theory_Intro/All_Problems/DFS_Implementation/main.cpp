#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=rEa4014IxR8&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=3

vector<int> adj[100001];
bool visited[100001];

void dfs(int node){
    visited[node] = true;
    cout<<node<<"->";
    for(int child: adj[node])
        if(visited[child] == 0)
            dfs(child);
}

int main(){
    int edges;
    cout<<"Enter the number of edges: \n";
    cin>>edges;
    for(int i = 0; i < edges; i++){
        int a, b;
        cout<<"Enter a pair of connected nodes: \n";
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);
    return 0;
}