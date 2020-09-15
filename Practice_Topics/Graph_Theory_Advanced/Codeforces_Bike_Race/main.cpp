#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codeforces.com/gym/102680/problem/G

vector<int> adj[100001];
bool vis[100001];
int dist[100001];
ll far;

void bfs(int node){
    queue<int> q;
    vis[node] = 1;
    q.push(node);
    dist[node] = 0;
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int child: adj[curr]){
            if(!vis[child]){
                q.push(child);
                dist[child] = dist[curr] + 1;
                vis[child] = 1;
            }
        }
    }
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, m;
        cin>>n>>m;
        for(int i = 0; i <= n; i++){
            vis[i] = 0;
            dist[i] = 0;
            adj[i].clear();
        }
        
        for(int i = 0; i < m; i++){
            ll a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        if(n == 1){
            cout<<"1\n";
            continue;
        }
        
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            far = 0;
            for(int j = 1; j <= n; j++){
                vis[j] = 0;
                dist[j] = 0;
            }
            
            bfs(i);
            for(int j = 1; j <= n; j++)
                far = max(far, (ll)dist[j]);
            //cout<<"FOR I: "<<i<<"   FURTHEST: "<<far<<endl;
            ans = max(ans, far);
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}

