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
    vector<array<int, 2>> v(n);
    for(auto &x: v)
        cin>>x[0]>>x[1];
    int l = 0, r = 1e9;
    int ans = -1;
    auto valid = [&](int r){
        vector<int> vis(n);
        int cnt = 0;
        auto dist = [&](int x, int y){
            return x * x + y * y;
        };
        function<void(int)> dfs = [&](int u){
            cnt++;
            vis[u] = 1;
            for(int c = 0; c < n; c++){
                if(!vis[c] && dist(v[u][0] - v[c][0], v[u][1] - v[c][1]) <= r){
                    dfs(c);
                }
            }
        };
        dfs(0);
        return cnt == n;
    };
    while(l <= r){
        int m = (l + r) / 2;
        if(valid(m)){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    cout<<ans<<"\n";
} 
