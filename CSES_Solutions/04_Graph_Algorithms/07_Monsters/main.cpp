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
    int startX, startY;
    vector<array<int, 2>> monsters;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
            if(a[i][j] == 'A')
                startX = i, startY = j;
            else if(a[i][j] == 'M')
                monsters.push_back({i, j});
        }
    }
    
    function<bool(int, int)> valid = [&](int x, int y){
        return (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '#'); 
    };
    
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<int>> dist(n, vector<int>(m, INF));
    queue<array<int, 3>> q;
    for(auto it: monsters){
        int x = it[0], y = it[1];
        q.push({x, y, 0});
        vis[x][y] = 1;
        dist[x][y] = 0;
    }
    
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int d = q.front()[2];
        q.pop();
        
        for(int i = 0; i < 4; i++){
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];
            if(valid(newX, newY) && !vis[newX][newY]){
                vis[newX][newY] = 1;
                dist[newX][newY] = d+1;
                q.push({newX, newY, d+1});
            }
        }
    }
    
    int endX = -1, endY = -1;
    vis = vector<vector<bool>>(n, vector<bool>(m));
    vector<vector<int>> from(n, vector<int>(m));
    
    q.push({startX, startY, 0});
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int d = q.front()[2];
        q.pop();
        if(x == 0 || x == n-1 || y == 0 || y == m-1){
            endX = x, endY = y;
            break;
        }
        for(int i = 0; i < 4; i++){
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];
            if(valid(newX, newY) && !vis[newX][newY] && d+1 < dist[newX][newY]){
                vis[newX][newY] = 1;
                q.push({newX, newY, d+1});
                from[newX][newY] = i;
            }
        }
    }
   
    if(endX != -1){
        string ans;
        while(endX != startX || endY != startY){
            int d = from[endX][endY];
            ans += dir2[d];
            endX -= dir[d][0];
            endY -= dir[d][1];
        }
        reverse(ans.begin(), ans.end());
        cout<<"YES\n"<<ans.size()<<endl<<ans<<endl;
    }
    else{
        cout<<"NO\n";
    }
    
    
    return 0;
}