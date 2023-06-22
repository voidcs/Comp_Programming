#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> adj(n+1);
        while(m--){
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<ll> vis(n+1), par(n+1);
        vector<vector<ll>> cc(n+1);
        function<void(ll, ll)> dfs = [&](ll u, ll parent){
            vis[u] = 1;
            cc[parent].push_back(u);
            par[u] = parent;
            for(int c: adj[u]){
                if(!vis[c])
                    dfs(c, parent);
            }
        };
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                dfs(i, i);
            }
        }
        for(int i = 1; i <= n; i++){
            sort(cc[i].begin(), cc[i].end());
        }
        auto best = [&](vector<ll> &v, ll x){
            ll res = INF;
            auto it = upper_bound(v.begin(), v.end(), x);
            if(it != v.end())
                res = abs(x - *it);
            if(it != v.begin()){
                res = min(res, abs(x - *(--it)));
            }
            return res;
        };
        vector<ll> min_cost(n+1, INF);
        ll ans = INF;
        for(int i = 1; i <= n; i++){
            //Try to connect 1 to i
            ll a = best(cc[par[1]], i);
            if(min_cost[par[i]] == INF){
                ll shortest = INF;
                for(ll x: cc[par[i]]){
                    shortest = min(shortest, best(cc[par[n]], x));
                }
                min_cost[par[i]] = shortest;
            }
            ll b = min_cost[par[i]];
            ans = min(ans, a * a + b * b);
        }
        cout<<ans<<"\n";
    }
} 
