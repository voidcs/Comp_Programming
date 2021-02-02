#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<ll>> dist(n, vector<ll>(m, INF));
    vector<vector<ll>> from(n, vector<ll>(m, -1));
    
    int sx, sy;
    queue<array<int, 2>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>g[i][j];
            if(g[i][j] == 'M'){
                dist[i][j] = 0;
                q.push({i, j});
            }
            else if(g[i][j] == 'A'){
                sx = i, sy = j;
            }
        }
    }
    
    function<bool(int, int)> valid = [&](int x, int y){
        return x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#';
    };
    
    array<int, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    char dir2[4] = {'D', 'R', 'U', 'L'};
    while(!q.empty()){
        int x = q.front()[0], y = q.front()[1];
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(valid(nx, ny) && dist[nx][ny] == INF){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    queue<array<int, 3>> q2;
    q2.push({sx, sy, 0});
    int endX = -1, endY = -1;
    while(!q2.empty()){
        int x = q2.front()[0], y = q2.front()[1], t = q2.front()[2];
        q2.pop();
        if(x == 0 || x == n-1 || y == 0 || y == m-1){
            endX = x, endY = y;
            break;
        }
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(valid(nx, ny) && t+1 < dist[nx][ny] && from[nx][ny] == -1){
                q2.push({nx, ny, t+1});
                from[nx][ny] = i;
            }
        }
    }
    
    if(endX == -1)
        cout<<"NO\n";
    else{
        cout<<"YES\n";
        string ans;
        while(endX != sx || endY != sy){
            int d = from[endX][endY];
            endX -= dir[d][0];
            endY -= dir[d][1];
            ans += dir2[d];
        }
        cout<<ans.length()<<endl;
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;
    }
 
    return 0;
}