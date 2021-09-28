#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<ll> dist(n+1, 0), last(n+1, -1);
    vector<vector<ll>> adj(n+1);
    while(m--){
        ll a, b;
        cin>>a>>b;
        adj[b].push_back(a);
    }
    priority_queue<array<ll, 2>> pq;
    pq.push({0, n});
    while(!pq.empty()){
        ll d = pq.top()[0];
        ll u = pq.top()[1];
        pq.pop();
        if(d < dist[u])
            continue;
        for(int c: adj[u]){
            if(dist[c] < d + 1){
                dist[c] = d+1;
                last[c] = u;
                pq.push({dist[c], c});
            }
        }
    }
    if(dist[1] == 0)
        cout<<"IMPOSSIBLE\n";
    else{
        vector<ll> ans;
        ans.push_back(1);
        ll curr = last[1];
        while(curr != -1){
            ans.push_back(curr);
            curr = last[curr];
        }
        cout<<ans.size()<<endl;
        for(auto x: ans)
            cout<<x<<" ";
        cout<<endl;
    }
    
    return 0;
}