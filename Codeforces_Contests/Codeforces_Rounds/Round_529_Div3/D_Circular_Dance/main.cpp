#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector<array<int, 2>> c(n+1);
    vector<set<int>> after(n+1);
    for(int i = 1; i <= n; i++){
        int a, b;
        cin>>a>>b;
        after[i].insert(a);
        after[i].insert(b);
        c[i] = {a, b};
    }
    queue<int> q;
    q.push(1);
    vector<int> vis(n+1), ans;
    while(q.size()){
        int u = q.front();
        q.pop();
        if(vis[u])
            continue;
        vis[u] = 1;
        ans.push_back(u);
        int x = c[u][0];
        int y = c[u][1];
        vis[u] = 1;
        if(after[x].count(y)){
            q.push(x);
            q.push(y);
        }
        else{
            q.push(y);
            q.push(x);
        }
    }
    
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}
