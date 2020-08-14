#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

//PROBLEM LINK
//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/jungle-run/
//REFERENCE VIDEO
//https://www.youtube.com/watch?v=8g95BQZwapA&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=36

int n;
char a[31][31];
bool vis[31][31];
int dist[31][31];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int x, int y){
    if(x < 1 || x > n || y < 1 || y > n)
        return false;
    if(vis[x][y] || a[x][y] == 'T')
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
    cin>>n;
    int startX, startY;
    int endX, endY;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>a[i][j];
            if(a[i][j] == 'S'){
                startX = i;
                startY = j;
            }
            if(a[i][j] == 'E'){
                endX = i;
                endY = j;
            }
        }
    }
    
    bfs(startX, startY);
    cout<<dist[endX][endY];
    
    return 0;
}