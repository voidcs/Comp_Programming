#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e8;
array<int, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char dir2[4] = {'D', 'R', 'U', 'L'};
 
int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<vector<char>> a(n, vector<char>(m));
    vector<vector<int>> dist(n, vector<int>(m, INF));
    
    queue<array<int, 2>> monsters;
    int startX, startY, endX = -1, endY = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
            if(a[i][j] == 'M')
                monsters.push({i, j});
            else if(a[i][j] == 'A')
                startX = i, startY = j;
        }
    }
    
    function<bool(int, int)> valid = [&](int x, int y){
        return (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#');
    };
    
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    queue<array<int, 3>> q;
    while(!monsters.empty()){
        int x = monsters.front()[0];
        int y = monsters.front()[1];
        vis[x][y] = 1;
        q.push({x, y, 0});
        dist[x][y] = 0;
        monsters.pop();
    }
    
    while(!q.empty()){
        int x, y, d;
        x = q.front()[0], y = q.front()[1];
        d = q.front()[2];
        q.pop();
        for(int i = 0; i < 4; i++){
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];
            if(valid(newX, newY) && !vis[newX][newY]){
                q.push({newX, newY, d+1});
                dist[newX][newY] = d+1;
                vis[newX][newY] = 1;
            }
        }
    }
 
    vector<vector<int>> from(n, vector<int>(m, -1));
    vis = vector<vector<bool>> (n, vector<bool>(m, 0));
    q.push({startX, startY, 0});
    vis[startX][startY] = 1;
    while(!q.empty()){
        int x, y, d;
        x = q.front()[0], y = q.front()[1];
        d = q.front()[2];
        vis[x][y] = 1;
        if(x == 0 || x == n-1 || y == 0 || y == m-1){
            endX = x, endY = y;
            break;
        }
        q.pop();
        for(int i = 0; i < 4; i++){
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];
            if(valid(newX, newY) && !vis[newX][newY] && d+1 < dist[newX][newY]){
                from[newX][newY] = i;
                vis[newX][newY] = 1;
                q.push({newX, newY, d+1});
            }
        }
    }
    if(endX == -1 && endY == -1)
        cout<<"NO\n";
    else{
        string ans;
        while(endX != startX || endY != startY){
            int d = from[endX][endY];
            ans += dir2[d];
            endX -= dir[d][0];
            endY -= dir[d][1];
        }
 
        reverse(ans.begin(), ans.end());
        cout<<"YES\n"<<ans.size()<<endl;
        cout<<ans<<endl;
    }
    
    return 0;
}