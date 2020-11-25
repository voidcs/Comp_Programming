#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    vector<bool> vis(n+1, 0);
    vector<int> last(n+1, -1);
    while(m--){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int curr = q.front();
        vis[curr] = 1;
        q.pop();
        for(int c: adj[curr]){
            if(!vis[c]){
                vis[c] = 1;
                last[c] = curr;
                q.push(c);
            }
        }
    }
    
    if(last[n] != -1){
        int curr = n;
        vector<int> ans;
        ans.push_back(n);
        while(n != 1){
            ans.push_back(last[n]);
            n = last[n];
        }
        reverse(ans.begin(), ans.end());
        cout<<ans.size()<<endl;
        for(auto x: ans)
            cout<<x<<" ";
    }
    else
        cout<<"IMPOSSIBLE\n";
    return 0;
}