#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e10;
array<int, 2> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<char>> a(n, vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];
    
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    
    function<bool(int, int)> isValid = [&](int x, int y){
        if(x < 0 || x >= n || y < 0 || y >= m)
            return false;
        if(vis[x][y] || a[x][y] == '#')
            return false;
        return true;
    };
    
    function<void(int, int)> dfs = [&](int x, int y){
        vis[x][y] = 1;
        for(int i = 0; i < 4; i++){
            if(isValid(x+dir[i][0], y+dir[i][1]))
                dfs(x+dir[i][0], y+dir[i][1]);
        }
    };
    
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!vis[i][j] && a[i][j] == '.'){
                ans++;
                dfs(i, j);
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}