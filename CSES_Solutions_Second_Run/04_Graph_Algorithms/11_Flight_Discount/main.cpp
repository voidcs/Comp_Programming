#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<vector<array<ll, 2>>> adj(n+1);
    vector<ll> dist(n+1, INF), usedDist(n+1, INF);
    while(m--){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
    }
    dist[0] = 0, usedDist[0] = 0;
    //Use priority queue holding {cost, u, if coupon has been used yet};
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    pq.push({0, 1, 0});
    while(!pq.empty()){
        ll d = pq.top()[0];
        ll u = pq.top()[1];
        ll used = pq.top()[2];
        pq.pop();
        if(used && d > usedDist[u])
            continue;
        if(!used && d > dist[u])
            continue;
        //If coupon has been used then we must pay full price
        if(used){
            for(array<ll, 2> a: adj[u]){
                ll cost_child = a[0];
                ll c = a[1];
                if(d + cost_child < usedDist[c]){
                    usedDist[c] = d + cost_child;
                    pq.push({usedDist[c], c, 1});
                }
            }
        }
        else if (!used){
            for(array<ll, 2> a: adj[u]){
                ll cost_child = a[0];
                ll c = a[1];
                //We can choose to not use the coupon
                if(d + cost_child < dist[c]){
                    dist[c] = d + cost_child;
                    pq.push({dist[c], c, 0});
                }
                //We can choose to use the coupon here
                if(d + (cost_child/2) < usedDist[c]){
                    usedDist[c] = d + (cost_child/2);
                    pq.push({usedDist[c], c, 1});
                }
            }
        }
    }
    cout<<usedDist[n]<<endl;
    
    return 0;
}