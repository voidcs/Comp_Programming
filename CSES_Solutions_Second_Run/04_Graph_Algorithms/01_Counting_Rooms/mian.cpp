#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<char>> g(n, vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>g[i][j];
    array<int, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int ans = 0;
    
    function<bool(int, int)> valid = [&](int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    
    function<void(int, int)> dfs = [&](int x, int y){
        g[x][y] = '#';
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(valid(nx, ny) && g[nx][ny] == '.'){
                g[nx][ny] = '#';
                dfs(nx, ny);
            }
        }
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == '.'){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}