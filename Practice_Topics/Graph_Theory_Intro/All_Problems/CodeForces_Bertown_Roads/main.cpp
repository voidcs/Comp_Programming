#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/118/E

//Reference video
//https://www.youtube.com/watch?v=ECKTyseo2H8&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=23

bool hasBridge;
vector<int> adj[1000001];   //Adjacency list
int vis[1000001];           //Marks true if node is visited
int in[1000001];            //Time at which node was visited (in time)
int low[1000001];           //Lowest time node could be visited
int timer;
vector<pair<int, int>> ans;

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
            if(in[node] > in[child])
                ans.push_back({node,child});
        }
        else{
            //This is a forward edge
            dfs(child, node);
            if(low[child] > in[node]){
                hasBridge = 1;
                return;
            }
            //update the low of this current node
            //if the child can obtain a lower low then this node must also
            //be able to obtain it if they are connected
            low[node] = min(low[node], low[child]);
            ans.push_back({node,child});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin>>n>>m;
    int a, b;
    while(m--){
        cin>>a>>b;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }
    
    //Pass -1 because we mark node 1 as the root
    //This means it has no parent
    dfs(1, -1);
    if(hasBridge){
        cout<<"0\n";
    }
    else{
        for(pair<int, int> x: ans){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    return 0;
}