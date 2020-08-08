#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Reference video
//https://www.youtube.com/watch?v=ECKTyseo2H8&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=23

vector<int> adj[1000001];   //Adjacency list
int vis[1000001];           //Marks true if node is visited
int in[1000001];            //Time at which node was visited (in time)
int low[1000001];           //Lowest time node could be visited
int timer;

void dfs(int node, int par){
    vis[node] = 1;
    in[node] = low[node] = timer;
    timer++;
    for(int child: adj[node]){
        
        //Ignore the parent of this node
        if(child == par)
            continue;

        if(vis[child] == 1){
            //Must be a backedge if this has been visited and not the parent
            //This visited node is an ancestor
            //Update the low time because it could've been visited via this ancestor
            low[node] = min(low[node], in[child]);
        }
        else{
            //This is a forward edge
            dfs(child, node);
            if(low[child] > in[node]){
                cout<<node<<" - "<<child<<" is a bridge\n";
            }
            //update the low of this current node
            //if the child can obtain a lower low then this node must also
            //be able to obtain it if they are connected
            low[node] = min(low[node], low[child]);
        }
    }
}

int main(){
    int n, m;
    cout<<"Enter the number of nodes and the number of edges\n";
    cin>>n>>m;
    
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    
    //Pass -1 because we mark node 1 as the root
    //This means it has no parent
    dfs(1, -1);
    
    return 0;
}