#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("ccski.in", "r", stdin);
    freopen("ccski.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> g(n, vector<int>(m)), waypoint(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>g[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>waypoint[i][j];
    int l = 0, r = 1e9;
    int ans = -1;
    auto valid = [&](int D){
        queue<array<int, 2>> q;
        vector<vector<int>> vis(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(waypoint[i][j] && q.empty()){
                    vis[i][j] = 1;
                    q.push({i, j});
                    break;
                }
            }
        }
        auto ok = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        array<int, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(q.size()){
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(ok(nx, ny) && !vis[nx][ny] && abs(g[nx][ny] - g[x][y]) <= D){
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && waypoint[i][j])
                    return false;
            }
        }
        return true;
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
