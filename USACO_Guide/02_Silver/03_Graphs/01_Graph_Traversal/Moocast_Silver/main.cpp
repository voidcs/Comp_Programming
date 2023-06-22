#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin>>n;
    vector<array<int, 3>> v(n);
    for(auto &x: v)
        cin>>x[0]>>x[1]>>x[2];
    int ans = 1;
    for(int i = 0; i < n; i++){
        //Start a bfs from cow i
        queue<int> q;
        vector<int> vis(n);
        vis[i] = 1;
        q.push(i);
        auto dist = [&](int x, int y){
            return x * x + y * y;
        };
        while(q.size()){
            int u = q.front();
            q.pop();
            for(int c = 0; c < n; c++){
                if(!vis[c] && dist(v[u][0] - v[c][0], v[u][1] - v[c][1]) <= v[u][2] * v[u][2]){
                    vis[c] = 1;
                    q.push(c);
                }
            }
        }
        ans = max(ans, accumulate(vis.begin(), vis.end(), 0));
    }
    cout<<ans<<"\n";
} 
