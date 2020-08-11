#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=yu4qdoG3618&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=33

int n, m;
int a[1001][1001];
bool vis[1001][1001];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int x, int y){
    if(x < 1 || x > n || y < 1 || y > m)
        return false;
    if(vis[x][y] || a[x][y] == 0)
        return false;
    
    return true;
}

void dfs(int x, int y){
    vis[x][y] = 1;

    for(int i = 0; i < 4; i++){
        if(isValid(x + dir[i][0], y + dir[i][1])){
            dfs(x + dir[i][0], y + dir[i][1]);
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>a[i][j];
        }
    }
    
    int connected_components = 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(vis[i][j] == 0 && a[i][j] == 1){
                dfs(i, j);
                connected_components++;
            }
        }
    }
    
    cout<<"There are "<<connected_components<<" connected components in this grid\n";
    return 0;
}
/*
 * Sample input: 
 * You can move on 1's
 * 0's are walls

0 0 1 0 1 1
0 1 1 0 0 1
0 1 0 0 0 0
1 0 1 1 0 0
0 0 0 1 0 0
0 1 1 0 1 1

 * Answer should be 6
*/