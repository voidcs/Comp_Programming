#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<array<ll, 2>> v(n);
    vector<vector<array<ll, 2>>> adj(n);
    for(int i = 0; i < n; i++){
        cin>>v[i][0]>>v[i][1];
        v[i][0]--;
        adj[v[i][0]].push_back({i, v[i][1]});
    }
    ll ans = 0;
    vector<int> vis(n);
    //It is guaranteed that no node points to itself (means we don't have to consider edge cases with cycles of length 1)
    function<void(int)> floyd = [&](int u){
        int x = u, y = u;
        do{
            x = v[x][0];
            y = v[v[y][0]][0];
        }while(x != y);
        //At this point both x and y are in the cycle
        ll cycle_sum = 0;
        do{
            cycle_sum += v[x][1];
            vis[x] = 1;
            x = v[x][0];
        }while(x != y);
        //We can get all except one edge in the cycle
        //We can always take the non-cyclic edges
        ll best = 0;
        ll sum = 0;
        function<void(int)> reverse_dfs = [&](int u){
            for(auto [c, w]: adj[u]){
                if(!vis[c]){
                    sum += w;
                    vis[c] = 1;
                    reverse_dfs(c);
                }
            }
        };
        do{
            reverse_dfs(x);
            x = v[x][0];
            best = max(best, cycle_sum - v[x][1]);
        }while(x != y);
        best += sum;
        ans += best;
    };
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            floyd(i);
        }
    }
    cout<<ans<<"\n";
}
