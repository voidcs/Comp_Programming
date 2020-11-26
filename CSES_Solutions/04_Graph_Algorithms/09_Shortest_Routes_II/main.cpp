#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>> adj(n+1, vector<ll>(n+1, INF));
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
    }
    
    for(int i = 1; i <= n; i++)
        adj[i][i] = 0;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
   
    while(q--){
        int a, b;
        cin>>a>>b;
        if(adj[a][b] == INF)
            cout<<"-1\n";
        else
            cout<<adj[a][b]<<endl;
    }
        
    return 0;
}