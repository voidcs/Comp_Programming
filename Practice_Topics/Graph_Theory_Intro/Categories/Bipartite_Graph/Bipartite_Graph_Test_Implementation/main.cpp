#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=MtFPqCcsoeA&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=9

vector<int> adj[100001];
bool visited[100001];
int col[100001];

bool dfs(int node, int c){
    visited[node] = 1;
    col[node] = c;
    
    for(int child: adj[node]){
        if(visited[child] == 0){
            bool res = dfs(child, c^1);
            if(!res)
                return false;
        }
        else{
            if(col[node] == col[child])
                return false;
        }
    }
    
    return true;
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
    
    bool flag = 1;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            flag = dfs(i, 0);
            if(!flag)
                break;
        }
    }
    
    if(flag)
        cout<<"The graph is bipartite\n";
    else
        cout<<"The graph is not bipartite\n";
    
    return 0;
}