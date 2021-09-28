#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    while(m--){
        ll a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<ll> active(n+1, 0), vis(n+1, 0), last(n+1, -1);
    
    function<void(ll)> dfs = [&](ll u){
        vis[u] = 1;
        active[u] = 1;
        for(int c: adj[u]){
            if(!vis[c]){
                last[c] = u;
                dfs(c);
            }
            else{
                if(active[c]){
                    vector<ll> cycle;
                    cycle.push_back(u);
                    ll curr = u;
                    while(curr != c){
                        curr = last[curr];
                        cycle.push_back(curr);
                    }
                    cycle.push_back(u);
                    reverse(cycle.begin(), cycle.end());
                    cout<<cycle.size()<<endl;
                    for(auto x: cycle)
                        cout<<x<<" ";
                    cout<<endl;
                    exit(0);
                }
            }
        }
        active[u] = 0;
    };

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    cout<<"IMPOSSIBLE\n";
    
    return 0;
}