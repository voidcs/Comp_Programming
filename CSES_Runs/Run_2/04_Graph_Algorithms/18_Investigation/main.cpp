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
    vector<ll> dist(n+1, INF);
    vector<ll> numWays(n+1, 0), min_f(n+1, 0), max_f(n+1, 0);
    while(m--){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
    }
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    numWays[1] = 1;
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        ll d = pq.top()[0];
        ll u = pq.top()[1];
        pq.pop();
        if(d > dist[u])
            continue;
        for(array<ll, 2> a: adj[u]){
            ll cost = a[0];
            ll c = a[1];
            //If this route is equal to dist[c], update numWays and min/max flights
            if(d + cost == dist[c]){
                numWays[c] += numWays[u];
                numWays[c] %= mod;
                min_f[c] = min(min_f[c], min_f[u]+1);
                max_f[c] = max(max_f[c], max_f[u]+1);
            }
            //Number of ways to get to c is equal to number of ways to get to u
            //Min flights of c is min flights of u + 1
            //Max flights of c is max flights of u + 1
            else if(d + cost < dist[c]){
                dist[c] = d + cost;
                pq.push({dist[c], c});
                numWays[c] = numWays[u];
                min_f[c] = min_f[u]+1;
                max_f[c] = max_f[u]+1;
            }
        }
        
    }
    cout<<dist[n]<<" "<<numWays[n]<<" "<<min_f[n]<<" "<<max_f[n]<<endl;

    return 0;
}