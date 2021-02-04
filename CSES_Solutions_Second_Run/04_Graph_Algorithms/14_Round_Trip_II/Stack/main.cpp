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
    vector<ll> active(n+1, 0), vis(n+1, 0);
    stack<ll> s;
    
    function<bool(ll)> dfs = [&](ll u){
        vis[u] = 1;
        active[u] = 1;
        s.push(u);
        for(int c: adj[u]){
            if(!vis[c]){
                if(dfs(c))
                    return true;
            }
            else{
                if(active[c]){
                    s.push(c);
                    return true;
                }
            }
        }
        s.pop();
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
        ll start = s.top();
        cycle.push_back(start);
        s.pop();
        while(s.top() != start){
            cycle.push_back(s.top());
            s.pop();
        }
        cycle.push_back(start);
        
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