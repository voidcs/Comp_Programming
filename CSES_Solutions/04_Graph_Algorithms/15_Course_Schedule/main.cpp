#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    vector<int> in(n+1, 0);
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!in[i])
            q.push(i);
    }
    
    vector<int> ans;
    while(!q.empty()){
        int u = q.front();
        ans.push_back(u);
        q.pop();
        for(int c: adj[u]){
            in[c]--;
            if(!in[c])
                q.push(c);
        }
    }
    
    if(ans.size() != n)
        cout<<"IMPOSSIBLE\n";
    else{
        for(auto x: ans)
            cout<<x<<" ";
    }

    return 0;
}