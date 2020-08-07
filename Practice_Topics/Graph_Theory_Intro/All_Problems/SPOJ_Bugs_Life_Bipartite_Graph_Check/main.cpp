#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//REFERENCE VIDEO
//https://www.spoj.com/problems/BUGLIFE/

vector<int> adj[100001];
bool vis[100001];
int col[100001];

bool dfs(int node, int c){
    vis[node] = 1;
    col[node] = c;
    
    for(int child: adj[node]){
        if(vis[child] == 0){
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
    int t;
    cin>>t;
    
    for(int tc = 1; tc <= t; tc++){
        int n, m;
        cin>>n>>m;
        
        for(int i = 1; i <= n; i++){
            adj[i].clear();
            vis[i] = 0;
        }
        
        for(int i = 0; i < m; i++){
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        bool flag = 1;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                bool res = dfs(i, 0);
                
                if(!res)
                    flag = 0;
            }
        }
        
        cout<<"Scenario #"<<tc<<":\n";
        if(flag)
            cout<<"No suspicious bugs found!\n";
        else
            cout<<"Suspicious bugs found!\n";
    }
    
    return 0;
}