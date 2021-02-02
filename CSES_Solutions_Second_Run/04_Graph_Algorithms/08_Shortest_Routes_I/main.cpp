#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<vector<array<ll, 2>>> adj(n+1);
    vector<ll> dist(n+1, INF);
    while(m--){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
    }
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        ll u = pq.top()[1];
        ll cost = pq.top()[0];
        pq.pop();
        if(cost > dist[u])
            continue;
        for(array<ll, 2> child: adj[u]){
            ll c = child[1];
            ll child_cost = child[0];
            ll new_cost = cost + child_cost;
            if(new_cost < dist[c]){
                dist[c] = new_cost;
                pq.push({new_cost, c});
            }
        }
    }
    for(int i = 1; i <= n; i++)
        cout<<dist[i]<<" ";
    cout<<endl;
    
 
    return 0;
}