#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<ll>> dist(n+1, vector<ll>(n+1, INF));
    for(int i = 1; i <= n; i++)
        dist[i][i] = 0;
    while(m--){
        ll a, b, c;
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while(q--){
        ll a, b;
        cin>>a>>b;
        if(dist[a][b] == INF)
            cout<<"-1\n";
        else
            cout<<dist[a][b]<<endl;
    }
    
    
    return 0;
}