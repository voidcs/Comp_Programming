#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<char>> g(n, vector<char>(m));
    int startX, startY, endX, endY;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>g[i][j];
            if(g[i][j] == 'E')
                endX = i, endY = j;
            if(g[i][j] == 'S')
                startX = i, startY = j;
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[endX][endY] = 0;
    queue<array<int, 2>> q;
    q.push({endX, endY});
    array<int, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while(q.size()){
        int x = q.front()[0];
        int y = q.front()[1];
        q.pop();
        auto valid = [&](int i, int j){
            return i >= 0 && i < n && j >= 0 && j < m;
        };
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(valid(nx, ny) && dist[nx][ny] == 1e9 && g[nx][ny] != 'T'){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    ll ans = 0;
    vector<vector<int>> dist2(n, vector<int>(m, 1e9));
    dist2[startX][startY] = 0;
    q.push({startX, startY});
    while(q.size()){
        int x = q.front()[0];
        int y = q.front()[1];
        q.pop();
        auto valid = [&](int i, int j){
            return i >= 0 && i < n && j >= 0 && j < m;
        };
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(valid(nx, ny) && dist2[nx][ny] == 1e9 && g[nx][ny] != 'T'){
                dist2[nx][ny] = dist2[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] != 'T' && g[i][j] != 'S' && g[i][j] != 'E'){
                if(dist[i][j] <= dist2[endX][endY])
                    ans += g[i][j] - '0';
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
