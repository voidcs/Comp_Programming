#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    int sx, sy, endX, endY;
    cin>>n>>m;
    vector<vector<char>> g(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>g[i][j];
            if(g[i][j] == 'A')
                sx = i, sy = j;
            else if(g[i][j] == 'B')
                endX = i, endY = j;
        }
    }
    
    array<int, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    char dir2[4] = {'D', 'R', 'U', 'L'};
    vector<vector<int>> dist(n, vector<int>(m, 1e6));
    vector<vector<int>> from(n, vector<int>(m, -1)), vis(n, vector<int>(m, 0));
    dist[sx][sy] = 0;
    
    function<bool(int, int)> valid = [&](int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y];
    };
    
    queue<array<int, 2>> q;
    q.push({sx, sy});
    while(!q.empty()){
        int x = q.front()[0], y = q.front()[1];
        q.pop();
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(valid(nx, ny) && g[nx][ny] != '#'){
                from[nx][ny] = i;
                vis[nx][ny] = 1;
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    if(dist[endX][endY] == 1e6){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        cout<<dist[endX][endY]<<endl;
        string ans;
        while(dist[endX][endY] != 0){
            int d = from[endX][endY];
            int dx = dir[d][0];
            int dy = dir[d][1];
            ans += dir2[d];
            endX -= dx;
            endY -= dy;
        }
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;
    }
    
    return 0;
}