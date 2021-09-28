#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<ll> deg(n+1, 0);
    vector<vector<ll>> adj(n+1);
    while(m--){
        ll a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        deg[b]++;
    }
    queue<ll> q;
    vector<ll> ans;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0){
            ans.push_back(i);
            q.push(i);
        }
    }
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(int c: adj[u]){
            deg[c]--;
            if(deg[c] == 0){
                ans.push_back(c);
                q.push(c);
            }
        }
    }
    if(ans.size() == n){
        for(auto x: ans)
            cout<<x<<" ";
        cout<<endl;
    }
    else{
        cout<<"IMPOSSIBLE\n";
    }
    
    
    return 0;
}