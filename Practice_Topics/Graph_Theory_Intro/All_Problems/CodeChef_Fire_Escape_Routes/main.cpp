#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://www.codechef.com/problems/FIRESC

ll mod = 1e9 + 7;
vector<int> adj[100001];
int vis[100001];
int size;

void dfs(int node){
    vis[node] = 1;
    size++;
    for(int child: adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n, m;
        cin>>n>>m;
        
        for(int i = 1; i <= n; i++){
            vis[i] = 0;
            adj[i].clear();
        }
        
        for(int i = 1; i <= m; i++){
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int count = 0;
        ll ans = 1;
        
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                size = 0;
                dfs(i);
                count++;
                ans = (ans*size) % mod;
            }
        }
        cout<<count<<" "<<ans<<endl;
    }
    
    return 0;
}