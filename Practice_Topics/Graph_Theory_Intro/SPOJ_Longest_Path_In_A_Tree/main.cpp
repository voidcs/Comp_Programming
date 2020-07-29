#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://www.spoj.com/problems/PT07Z/

vector<int> adj[100001];
bool vis[100001];

int maxDist, maxNode;

void dfs(int node, int d){
    if(d > maxDist){
        maxNode = node;
        maxDist = d;
    }
    
    vis[node] = 1;
    for(int child: adj[node]){
        if(!vis[child]){
            dfs(child, d+1);
        }
    }
}


int main(){
    ll n;
    cin>>n;
    for(int i = 0 ; i < n-1; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    maxDist = -1;
    //First do a dfs to find the furthest node from 1
    //This is guaranteed to be a node on the perimeter
    dfs(1, 0);
    
    //cout<<"Furthest node is: "<<maxNode<<endl;
    
    //Set values back to default because we already did a dfs
    maxDist = -1;
    for(int i = 1; i <= n; i++)
        vis[i] = 0;
    
    //Now do another dfs with the node found on the perimeter
    //The new max distance will be from this perimeter to the other perimeter of the graph
    dfs(maxNode, 0);
    
    cout<<maxDist<<endl;
    
    return 0;
}