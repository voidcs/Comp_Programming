#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=eCG3T1m7rFY&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=11

vector<int> adj[100001];
bool vis[100001];

bool dfs(int node, int par){
    vis[node] = 1;
    
    for(int child: adj[node]){
        if(vis[child] == 0){
            if(dfs(child, node)){
                return true;
            }
        }
        else{
            if(child != par)
                return true;
        }
    }
    return false;
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
    
    bool containsCycle = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            bool flag = dfs(i, 0);
            if(flag)
                containsCycle = 1;
        }
    }
    
    if(containsCycle)
        cout<<"The graph contains a cycle\n";
    else
        cout<<"The graph does not contain a cycle\n";
    
    
    
    return 0;
}