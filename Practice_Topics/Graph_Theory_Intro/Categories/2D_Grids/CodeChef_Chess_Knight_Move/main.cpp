#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

//PROBLEM LINK
//https://www.codechef.com/problems/PRGCUP01
//REFERENCE VIDEO
//https://www.youtube.com/watch?v=L8bhfw2bWY4&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=38

int n = 8;
bool vis[9][9];
int dist[9][9];
int dir[8][2] = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}};

bool isValid(int x, int y){
    if(x < 1 || x > n || y < 1 || y > n)
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
        
        for(int i = 0; i < 8; i++){
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
    int t;
    cin>>t;
    while(t--){
        for(int i = 1; i <= 8; i++){
            for(int j = 1; j <= 8; j++){
                vis[i][j] = 0, dist[i][j] = 0;
            }
        }
        string start, end;
        cin>>start>>end;
        
        int startX = start[0] - 'a' + 1;
        int startY = start[1] - '0';
        int endX = end[0] - 'a' + 1;
        int endY = end[1] - '0';
        
        bfs(startX, startY);
        cout<<dist[endX][endY]<<endl;
    }
 
    return 0;
}