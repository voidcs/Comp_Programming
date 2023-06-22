#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    int x, y, k, m;
    cin>>x>>y>>k>>m;
    vector<vector<vector<int>>> vis(x+1, vector<vector<int>>(y+1, vector<int>(k+1)));
    int ans = m;
    function<void(int, int, int)> dfs = [&](int a, int b, int steps){
        if(steps > k)
            return;
        ans = min(ans, abs(m - (a + b)));
        vis[a][b][steps] = 1;
        //Fill second bucket
        if(!vis[a][y][steps+1]){
            dfs(a, y, steps + 1);
        }
        //Fill first bucket
        if(!vis[x][b][steps+1]){
            dfs(x, b, steps + 1);
        }
        //Empty first bucket
        if(!vis[0][b][steps+1]){
            dfs(0, b, steps + 1);
        }
        //Empty second bucket
        if(!vis[a][0][steps+1]){
            dfs(a, 0, steps + 1);
        }
        //Pour first bucket into second
        if(!vis[a - min(y - b, a)][b + min(y - b, a)][steps+1]){
            dfs(a - min(y - b, a), b + min(y - b, a), steps + 1);
        }
        //Pour second bucket into first
        if(!vis[a + min(x - a, b)][b - min(x - a, b)][steps+1]){
            dfs(a + min(x - a, b), b - min(x - a, b), steps + 1);
        }
    };
    dfs(0, 0, 0);
    cout<<ans<<"\n";
}
