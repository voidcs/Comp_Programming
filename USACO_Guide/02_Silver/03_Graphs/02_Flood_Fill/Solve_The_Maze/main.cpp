#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n, m;
        cin>>n>>m;
        vector<string> g(n);
        for(int i = 0; i < n; i++)
            cin>>g[i];
        vector<vector<int>> vis(n, vector<int>(m));
        array<int, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        auto valid = [&](int x, int y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == 'B'){
                    for(int d = 0; d < 4; d++){
                        int ni = i + dir[d][0];
                        int nj = j + dir[d][1];
                        if(valid(ni, nj) && g[ni][nj] == '.')
                            g[ni][nj] = '#';
                    }
                }
            }
        }
        function<void(int, int)> dfs = [&](int x, int y){
            vis[x][y] = 1;
            for(int i = 0; i < 4; i++){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(valid(nx, ny) && !vis[nx][ny] && g[nx][ny] != '#'){
                    dfs(nx, ny);
                }
            }
        };
        if(g[n-1][m-1] != '#')
            dfs(n-1, m-1);
        bool ok = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(g[i][j] == 'B' && vis[i][j])
                    ok = 0;
                if(g[i][j] == 'G' && !vis[i][j])
                    ok = 0;
            }
        }

        if(ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}
