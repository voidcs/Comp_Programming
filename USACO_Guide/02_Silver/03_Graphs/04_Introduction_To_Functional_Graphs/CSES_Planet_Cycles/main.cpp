#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    vector<vector<int>> adj(n); //Backwards adjacency list to mark non-cycle nodes as visited
    for(int i = 0; i < n; i++){
        cin>>v[i];
        v[i]--;
        adj[v[i]].push_back(i);
    }
    vector<int> ans(n, -1);
    vector<int> vis(n);
    function<void(int)> reverse_dfs = [&](int u){
        for(int c: adj[u]){
            if(ans[c] == -1){   //Will only execute on the first cycle node or on a non-cycle node!!!
                ans[c] = ans[u] + 1;
                reverse_dfs(c);
            }
        }
    };
    function<void(int)> floyd = [&](int u){
        int x = u;
        int y = u;
        do{
            x = v[x];
            y = v[v[y]];
        }while(x != y);
        //Now x and y met in the cycle
        //Find size of connected component
        int cc = 0;
        do{
            x = v[x];
            cc++;
        }while(x != y);
        do{
            ans[x] = cc;
            x = v[x];
        }while(x != y);
        //Mark all non cycle nodes as visited
        do{
            reverse_dfs(x);
            x = v[x];
        }while(x != y);
    };
    for(int i = 0; i < n; i++){
        if(ans[i] == -1){
            floyd(i);
        }
    }
    for(int x: ans)
        cout<<x<<" ";
    cout<<"\n";
}
