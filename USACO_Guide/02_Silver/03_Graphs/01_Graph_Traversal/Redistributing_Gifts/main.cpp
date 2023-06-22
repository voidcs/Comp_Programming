#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>v[i][j];
            v[i][j]--;
        }
    }
    vector<vector<int>> adj(n); //Stores all cows gift i can go to
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i][j] == i)
                break;
            adj[v[i][j]].push_back(i);
        }
    }
    for(int x = 0; x < n; x++){
        //Traverse from gift x 
        vector<int> vis(n);
        function<void(int)> dfs = [&](int u){
            vis[u] = 1;
            for(int c: adj[u]){
                if(!vis[c])
                    dfs(c);
            }
        };
        dfs(x);
        //Take the first gift on their list that's visited
        for(int i = 0; i < n; i++){
            if(vis[v[x][i]]){
                cout<<v[x][i] + 1<<"\n";
                break;
            }
        }
    }
} 
