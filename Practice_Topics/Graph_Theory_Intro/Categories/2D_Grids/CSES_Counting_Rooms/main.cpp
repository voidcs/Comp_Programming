#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

//PROBLEM LINK
//https://cses.fi/problemset/task/1192/
//REFERENCE VIDEO
//https://www.youtube.com/watch?v=QrZAee1PZBE&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=34

int n, m;
char a[1001][1001];
bool vis[1001][1001];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int x, int y){
    if(x < 1 || x > n || y < 1 || y > m)
        return false;
    if(vis[x][y] || a[x][y] == '#')
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
            if(vis[i][j] == 0 && a[i][j] == '.'){
                dfs(i, j);
                connected_components++;
            }
        }
    }
    
    cout<<connected_components;
    return 0;
}