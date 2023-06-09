#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    int n;
    cin>>n;
    vector<vector<char>> g(n, vector<char>(n));
    vector<vector<int>> vis(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>g[i][j];
    array<int, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    auto valid = [&](int x, int y){
        return x >= 0 && x < n && y >= 0 && y < n;
    };
    int perimeter = 0, area = 0;
    function<void(int, int)> dfs = [&](int x, int y){
        area++;
        int cnt = 0;
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(valid(nx, ny) && g[nx][ny] == '#'){
                cnt++;
                if(!vis[nx][ny]){
                    dfs(nx, ny);
                }
            }
        }
        perimeter += 4 - cnt;
    };
    int ans1 = 0, ans2 = 1e9;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!vis[i][j] && g[i][j] == '#'){
                perimeter = 0, area = 0;
                dfs(i, j);
                if(area > ans1){
                    ans1 = area;
                    ans2 = perimeter;
                }
                else if(area == ans1){
                    ans2 = min(ans2, perimeter);
                }
            }
        }
    }
    cout<<ans1<<" "<<ans2<<"\n";
}
