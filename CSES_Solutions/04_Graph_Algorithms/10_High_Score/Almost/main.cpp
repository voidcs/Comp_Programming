#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<vector<array<ll, 2>>> adj(n+1);
    vector<ll> dist(n+1, -INF);
    vector<bool> vis(n+1, 0);
    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
    }
    
    priority_queue<pair<array<ll, 3>, set<ll>>> pq;
    pq.push({{0, 1, -1}, {1}});
    dist[1] = 0;
    function<void(int)> dfs = [&](int u){
        vis[u] = 1;
        for(array<ll, 2> a: adj[u]){
            if(!vis[a[1]])
                dfs(a[1]);
        }
    };
    while(!pq.empty()){
        ll cost = pq.top().first[0];
        ll u = pq.top().first[1];
        ll par = pq.top().first[2];
        set<ll> s = pq.top().second;
        if(s.count(-1)){
            vis = vector<bool> (n+1, 0);
            dfs(u);
            if(vis[n]){
                cout<<"-1\n";
                return 0;
            }
        }
        if(u == n && s.count(-1)){
            cout<<"-1\n";
            return 0;
        }
        if(s.count(n) && s.count(-1)){
            cout<<"-1\n";
            return 0;
        }
        pq.pop();
        if(cost > dist[u] && !s.count(-1))
            continue;
        
        bool flag = 1;
        for(array<ll, 2> a: adj[u]){
            if(!s.count(a[1])){
                flag = 0;
            }
        }
        if(flag && s.count(-1)){
            continue;
        }
        for(array<ll, 2> a: adj[u]){
            int cost_child = a[0];
            int child = a[1];
            
            if(s.count(-1) && !s.count(child)){
                s.insert(child);
                pq.push({{INF, child, u}, s});
                continue;
            }
            
            if(cost_child + cost > 0 && par != -1 && s.count(child) && !s.count(-1)){
                s.insert(-1);
                pq.push({{dist[child], u, -1}, s});
                pq.push({{dist[child], child, -1}, s});
            }
            
            if((child == n || s.count(n)) && s.count(-1)){
                cout<<"-1\n";
                return 0;
            }
            if(dist[child] <= cost + cost_child){
                dist[child] = cost + cost_child;
                s.insert(child);
                pq.push({{dist[child], child, u}, s});
            }
        }
    }
    cout<<dist[n];
    return 0;
}