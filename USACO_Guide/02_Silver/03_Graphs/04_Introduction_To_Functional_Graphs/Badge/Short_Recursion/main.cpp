#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v){
        cin>>x;
        x--;
    }
    vector<int> active(n), ans(n, -2), vis(n);
    int cycle_start = -1;
    function<bool(int)> dfs = [&](int u){
        bool in_cycle = false;
        active[u] = 1;
        vis[u] = 1;
        if(!vis[v[u]]){
            in_cycle = dfs(v[u]);
        }
        else{
            if(active[v[u]]){
                cycle_start = v[u];
                in_cycle = true;
            }
        }
        if(in_cycle)
            ans[u] = u;
        else
            ans[u] = ans[v[u]];
        active[u] = 0;
        if(u == cycle_start)    //We've exited the cycle
            in_cycle = 0;
        return in_cycle;
    };
    for(int i = 0; i < n; i++){
        if(!vis[i])
            dfs(i);
    }
    for(int i = 0; i < n; i++)
        cout<<ans[i]+1<<" ";
    cout<<"\n";
}
