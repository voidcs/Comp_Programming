#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    vector<set<int>> adj(n+1);
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    set<int> unvis;
    for(int i = 1; i <= n; i++)
        unvis.insert(i);
    int cnt = 0;
    function<void(int)> dfs = [&](int u){
        unvis.erase(u);
        cnt++;
        auto it = unvis.begin();
        while(it != unvis.end()){
            if(!adj[u].count(*it)){
                int v = *it;
                dfs(v);
                it = unvis.upper_bound(v);
            }
            else{
                it++;
            }
        }
    };
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(unvis.count(i)){
            cnt = 0;
            dfs(i);
            ans.push_back(cnt);
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<"\n";
    for(int x: ans)
        cout<<x<<" ";
    cout<<"\n";
} 