#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
vector<ll> adj[100005];
vector<ll> a;
int vis[100005];
ll min_node;

int main(){
    ll n, m;
    cin>>n>>m;
    a = vector<ll> (n+1);
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    
    for(int i = 0; i < m; i++){
        ll x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    function<void(ll)> dfs = [&](ll node){
        vis[node] = 1;
        min_node = min(min_node, a[node]);
        for(int child: adj[node]){
            if(!vis[child])
                dfs(child);
        }
    };
    
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            min_node = a[i];
            dfs(i);
            ans += min_node;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}