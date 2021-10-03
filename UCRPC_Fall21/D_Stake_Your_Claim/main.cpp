#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    int n, m;
    cin>>n>>m;
    n = n*2+1;
    m = m*2+1;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>v[i][j];
    array<int, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    auto valid = [&](int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    vector<int> ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i%2 && j%2 && !vis[i][j] && v[i][j] == '.'){
                int cnt = 0;
                function<void(int, int)> dfs = [&](int x, int y){
                    cnt++;
                    vis[x][y] = 1;
                    for(int d = 0; d < 4; d++){
                        int nx = x + (dir[d][0]*2);
                        int ny = y + (dir[d][1]*2);
                        int bx = x + dir[d][0];
                        int by = y + dir[d][1];
                        if(valid(bx, by) && (v[bx][by] == '|' || v[bx][by] == '-'))
                            continue;
                        if(valid(nx, ny) && !vis[nx][ny] && v[nx][ny] == '.'){
                            vis[nx][ny] = 1;
                            dfs(nx, ny);
                        }
                    }
                };
                vis[i][j] = 1;
                dfs(i, j);
                if(cnt)
                    ans.push_back(cnt);
            }
        }
    }
    sort(ans.rbegin(), ans.rend());
    for(auto x: ans)
        cout<<x<<" ";
    
    return 0;
}