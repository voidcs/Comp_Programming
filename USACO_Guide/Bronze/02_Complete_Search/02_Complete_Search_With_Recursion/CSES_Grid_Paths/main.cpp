#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int ans = 0;
bool vis[7][7];
bool valid(int x, int y){
    return x >= 0 && x < 7 && y >= 0 && y < 7 && !vis[x][y];
}
void dfs(vector<char> &s, int i, int x, int y, int cnt){
    if(x == 6 && y == 0){
        if(i == 48)
            ans++;
        return;
    }
    vis[x][y] = 1;
    if(s[i] == '?' || s[i] == 'U'){
        int nx = x - 1, ny = y;
        if(valid(nx, ny) && !(!valid(nx-1, ny) && valid(nx, ny+1) && valid(nx, ny-1))){
            dfs(s, i+1, nx, ny, cnt+1);
        }
    }
    if(s[i] == '?' || s[i] == 'D'){
        int nx = x + 1, ny = y;
        if(valid(nx, ny) && !(!valid(nx+1, ny) && valid(nx, ny+1) && valid(nx, ny-1))){
            dfs(s, i+1, nx, ny, cnt+1);
        }
    }
    if(s[i] == '?' || s[i] == 'R'){
        int nx = x, ny = y + 1;
        if(valid(nx, ny) && !(!valid(nx, ny+1) && valid(nx+1, ny) && valid(nx-1, ny))){
            dfs(s, i+1, nx, ny, cnt+1);
        }
    }
    if(s[i] == '?' || s[i] == 'L'){
        int nx = x, ny = y - 1;
        if(valid(nx, ny) && !(!valid(nx, ny-1) && valid(nx+1, ny) && valid(nx-1, ny))){
            dfs(s, i+1, nx, ny, cnt+1);
        }
    }
    vis[x][y] = 0;
}

int main(){
    //freopen("input.txt", "r", stdin);
    vector<char> s(48);
    for(int i = 0; i < 48; i++)
        scanf("%c", &s[i]);
    dfs(s, 0, 0, 0, 0);
    cout<<ans<<endl;
    
    return 0;
}