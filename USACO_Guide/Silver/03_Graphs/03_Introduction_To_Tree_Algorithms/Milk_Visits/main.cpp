#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<vector<int>> adj(n);
    for(int i = 1; i < n; i++){
        int a, b;
        cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<char> v(n);
    vector<int> vis(n), par(n);
    function<void(int, char, int)> dfs = [&](int u, char milk, int p){
        par[u] = p;
        vis[u] = 1;
        v[u] = milk;
        for(int c: adj[u]){
            if(s[c] == milk && !vis[c]){
                dfs(c, milk, p);
            }
        }
    };
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i, s[i], i);
        }
    }
    while(m--){
        int a, b;
        char c;
        cin>>a>>b>>c;
        a--, b--;
        if(par[a] == par[b]){
            if(v[par[a]] == c)
                cout<<"1";
            else
                cout<<"0";
        }
        else
            cout<<"1";
    }
}
