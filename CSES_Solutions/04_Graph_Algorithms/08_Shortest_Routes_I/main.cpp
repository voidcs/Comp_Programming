#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<vector<array<ll, 2>>> adj(n+1);
    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
    }
    
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    vector<ll> dist(n+1, INF);
    dist[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        ll cost = pq.top()[0];
        ll u = pq.top()[1];
        pq.pop();
        if(cost > dist[u])
            continue;
        for(array<ll, 2> a: adj[u]){
            int cost_child = a[0];
            int child = a[1];
            if(dist[child] > cost + cost_child){
                dist[child] = cost + cost_child;
                pq.push({dist[child], child});
            }
        }
    }

    for(int i = 1; i <= n; i++)
        cout<<dist[i]<<" ";
    
    return 0;
}