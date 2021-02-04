#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=g_1qUIlpuzg&feature=youtu.be

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<ll> cnt(n+1, 0), deg(n+1, 0);
    vector<vector<ll>> adj(n+1);
    while(m--){
        ll a, b;
        cin>>a>>b;
        deg[b]++;
        adj[a].push_back(b);
    }
    cnt[1] = 1;
    queue<ll> q;
    //We first have to perform topological sort to remove starting points
    //that aren't node 1. These starting points would clog the in degree
    //of nodes on the actual path and we wouldn't be able to add them to queue
    for(int i = 2; i <= n; i++){
        if(deg[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(int c: adj[u]){
            deg[c]--;
            if(deg[c] == 0)
                q.push(c);
        }
    }
    
    //Now perform topological sort with node 1 as starting point
    //since all nodes not on the path from 1 to n are removed.
    q.push(1);
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        for(int c: adj[u]){
            deg[c]--;
            cnt[c] += cnt[u];
            cnt[c] %= mod;
            if(deg[c] == 0){
                q.push(c);
            }
        }
    }
    cout<<cnt[n]<<endl;
    
    return 0;
}