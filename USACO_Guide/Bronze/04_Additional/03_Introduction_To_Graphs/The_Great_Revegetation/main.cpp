#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans(n+1);
    ans[1] = 1;
    for(int i = 2; i <= n; i++){
        set<int> s;
        for(int j = 1; j <= 4; j++)
            s.insert(j);
        for(int x: adj[i]){
            s.erase(ans[x]);
        }
        ans[i] = *s.begin();
    }
    for(int i = 1; i <= n; i++)
        cout<<ans[i];
    cout<<endl;
    return 0;
}
