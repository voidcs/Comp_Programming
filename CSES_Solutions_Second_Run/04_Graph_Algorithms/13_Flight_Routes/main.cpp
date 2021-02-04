#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m, k;
    cin>>n>>m>>k;
    vector<vector<array<ll, 2>>> adj(n+1);
    //Distance array now stores the kth shortest distances for each node
    vector<vector<ll>> dist(n+1, vector<ll>(k, INF));
    for(int i = 0; i < k; i++)
        dist[0][i] = 0;
    while(m--){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
    }
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        ll d = pq.top()[0];
        ll u = pq.top()[1];
        pq.pop();
        if(d > dist[u][k-1])
            continue;
        for(array<ll, 2> a: adj[u]){
            ll cost = a[0];
            ll c = a[1];
            if(dist[c][k-1] > d + cost){
                dist[c][k-1] = d + cost;
                pq.push({d+cost, c});
                sort(dist[c].begin(), dist[c].end());
            }
        }
    }
    for(int i = 0; i < k; i++)
        cout<<dist[n][i]<<" ";
    cout<<endl;
    
    return 0;
}