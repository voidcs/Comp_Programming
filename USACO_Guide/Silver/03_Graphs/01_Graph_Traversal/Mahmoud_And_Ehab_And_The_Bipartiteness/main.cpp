#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> color(n+1, -1);
    function<void(int, int)> dfs = [&](int u, int col){
        color[u] = col;
        for(int c: adj[u]){
            if(color[c] == -1){
                dfs(c, col ^ 1);
            }
        }
    };
    dfs(1, 0);
    vector<int> cnt(2); //count of colors 0 and 1
    for(int i = 1; i <= n; i++){
        cnt[color[i]]++;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += cnt[!color[i]] - adj[i].size();
    }
    cout<<ans / 2<<"\n";
} 
