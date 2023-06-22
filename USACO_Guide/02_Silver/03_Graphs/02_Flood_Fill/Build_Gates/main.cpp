#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("gates.in", "r", stdin);
    freopen("gates.out", "w", stdout);
    array<int, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int x_min = 1e9, x_max = -1e9, y_min = 1e9, y_max = -1e9;
    int x = 0, y = 0;
    int n;
    string s;
    cin>>n>>s;
    for(char c: s){
        if(c == 'N')
            y += 2;
        else if(c == 'E')
            x += 2;
        else if(c == 'S')
            y -= 2;
        else if(c == 'W')
            x -= 2;
        x_min = min(x_min, x);
        x_max = max(x_max, x);
        y_min = min(y_min, y);
        y_max = max(y_max, y);
    }
    n = x_max - x_min + 2;
    int m = y_max - y_min + 2;
    vector<vector<bool>> g(n+1, vector<bool>(m+1)), vis(n+1, vector<bool>(m+1));
    x = -x_min + 1;
    y = -y_min + 1;
    for(char c: s){
        if(c == 'N')
            y++;
        else if(c == 'E')
            x++;
        else if(c == 'S')
            y--;
        else if(c == 'W')
            x--;
        g[x][y] = 1;
        if(c == 'N')
            y++;
        else if(c == 'E')
            x++;
        else if(c == 'S')
            y--;
        else if(c == 'W')
            x--;
        g[x][y] = 1;
    }
    int ans = 0;
    auto valid = [&](int x, int y){
        return x >= 0 && x <= n && y >= 0 && y <= m;
    };
    function<void(int, int)> dfs = [&](int x, int y){
        stack<array<int, 2>> s;
        s.push({x, y});
        while(s.size()){
            auto [x, y] = s.top();
            s.pop();
            vis[x][y] = 1;
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(valid(nx, ny) && !vis[nx][ny] && !g[nx][ny]){
                    s.push({nx, ny});
                }
            }
        }
    };
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(!vis[i][j] && !g[i][j]){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout<<ans - 1<<"\n";
}
