#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=M4xxztqh8rQ&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=35

int n, m;
bool vis[1001][1001];
int dist[1001][1001];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int x, int y){
    if(x < 1 || x > n || y < 1 || y > m)
        return false;
    if(vis[x][y])
        return false;
    
    return true;
}

void bfs(int x, int y){
    vis[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x,y});
    dist[x][y] = 0;
    while(!q.empty()){
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++){
            if(isValid(currX + dir[i][0], currY + dir[i][1])){
                int newX = currX + dir[i][0];
                int newY = currY + dir[i][1];
                q.push({newX, newY});
                vis[newX][newY] = 1;
                dist[newX][newY] = dist[currX][currY] + 1;
            }
        }
    }
}

int main(){
    
    cout<<"ENTER THE DIMENSIONS\n";
    cin>>n>>m;

    int startX, startY;
    cout<<"ENTER THE STARTING POSITION\n";
    cin>>startX>>startY;
    
    bfs(startX, startY);
    cout<<"DISTANCE ARRAY: \n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}