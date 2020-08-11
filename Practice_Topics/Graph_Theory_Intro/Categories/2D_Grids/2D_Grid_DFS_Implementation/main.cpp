#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=r7-T3Xe3UeI&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=32

int n, m;
bool vis[1001][1001];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValid(int x, int y){
    if(x < 1 || x > n || y < 1 || y > m)
        return false;
    if(vis[x][y])
        return false;
    
    return true;
}

void dfs(int x, int y){
    vis[x][y] = 1;
    
    cout<<x<<" "<<y<<endl;
    
    for(int i = 0; i < 4; i++){
        if(isValid(x + dir[i][0], y + dir[i][1])){
            dfs(x + dir[i][0], y + dir[i][1]);
        }
    }
}

int main(){
    cin>>n>>m;
    dfs(1, 1);
    return 0;
}