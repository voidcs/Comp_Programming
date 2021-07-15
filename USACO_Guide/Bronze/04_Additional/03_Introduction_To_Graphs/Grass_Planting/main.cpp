#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, (int)adj[i].size()+1);
    }
    cout<<ans<<endl;
    return 0;
}
