#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    vector<vector<int>> adj(n);
    vector<int> cnt(n, 0);
    function<void(int)> dfs = [&](int u){
        cnt[u] = 1;
        for(int c: adj[u]){
            dfs(c);
            cnt[u] += cnt[c];
        }
    };
    for(int i = 1; i < n; i++){
        int a;
        cin>>a;
        a--;
        adj[a].push_back(i);
    }
    dfs(0);
    for(auto x: cnt)
        cout<<x-1<<" ";
    cout<<endl;
    
    return 0;
}