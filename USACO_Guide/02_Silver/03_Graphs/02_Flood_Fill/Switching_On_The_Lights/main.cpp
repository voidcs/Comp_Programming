#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);
    array<int, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int n, q;
    cin>>n>>q;
    map<array<int, 2>, vector<array<int, 2>>> m;
    while(q--){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        m[{a, b}].push_back({c, d});
    }
    int ans = 0;
    vector<vector<int>> vis(n+1, vector<int>(n+1)), lit(n+1, vector<int>(n+1));
    auto valid = [&](int x, int y){
        return x > 0 && x <= n && y > 0 && y <= n;
    };
    lit[1][1] = 1;
    function<void(int, int)> dfs = [&](int x, int y){
        vis[x][y] = 1;
        if(m.count({x, y})){
            for(auto [a, b]: m[{x, y}]){
                lit[a][b] = 1;
                bool reachable = 0;
                for(int i = 0; i < 4; i++){
                    int na = a + dir[i][0];
                    int nb = b + dir[i][1];
                    if(valid(na, nb) && vis[na][nb] && !vis[a][b]){
                        reachable = 1;
                    }
                }
                if(reachable){
                    dfs(a, b);
                }
            }
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(valid(nx, ny) && !vis[nx][ny] && lit[nx][ny]){
                dfs(nx, ny);
            }
        }
    };
    dfs(1, 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            ans += lit[i][j];
        }
    }
    cout<<ans<<"\n";
}
