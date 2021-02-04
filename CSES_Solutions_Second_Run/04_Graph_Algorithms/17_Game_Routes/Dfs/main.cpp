#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<ll> cnt(n+1, 0), vis(n+1, 0);
    vector<vector<ll>> adj(n+1);
    while(m--){
        ll a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    cnt[n] = 1;
    
    function<void(ll)> dfs = [&](ll u){
        vis[u] = 1;
        for(int c: adj[u]){
            if(!vis[c]){
                vis[c] = 1;
                dfs(c);
            }
            cnt[u] += cnt[c];
            cnt[u] %= mod;
        }
    };
    dfs(1);
    cout<<cnt[1]<<endl;
    
    return 0;
}