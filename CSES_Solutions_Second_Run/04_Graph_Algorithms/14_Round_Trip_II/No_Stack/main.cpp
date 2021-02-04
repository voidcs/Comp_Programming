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
    ll ans = -1;
    function<bool(ll)> dfs = [&](ll u){
        vis[u] = 1;
        active[u] = 1;

        for(int c: adj[u]){
            if(!vis[c]){
                last[c] = u;
                if(dfs(c))
                    return true;
            }
            else{
                if(active[c]){
                    ans = u;
                    last[c] = u;
                    return true;
                }
            }
        }
        active[u] = 0;
        return false;
    };
    bool found = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            if(dfs(i)){
                found = 1;
                break;
            }
        }
    }
    if(found){
        vector<ll> cycle;
        ll curr = last[ans];
        cycle.push_back(ans);
        while(curr != ans){
            cycle.push_back(curr);
            curr = last[curr];
        }
        cycle.push_back(ans);
        
        reverse(cycle.begin(), cycle.end());
        cout<<cycle.size()<<endl;
        for(auto x: cycle)
            cout<<x<<" ";
        cout<<endl;
    }
    else
        cout<<"IMPOSSIBLE\n";
    
    return 0;
}