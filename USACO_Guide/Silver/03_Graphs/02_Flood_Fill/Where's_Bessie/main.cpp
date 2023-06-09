#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);
    int n;
    cin>>n;
    vector<vector<char>> g(n, vector<char>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>g[i][j];
    vector<array<int, 4>> ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int row = i; row < n; row++){
                for(int col = j; col < n; col++){
                    vector<vector<int>> vis(n, vector<int>(n));
                    map<char, int> m;
                    for(int a = i; a <= row; a++){
                        for(int b = j; b <= col; b++){
                            auto valid = [&](int x, int y){
                                return x >= i && x <= row && y >= j && y <= col;
                            };
                            array<int, 2> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
                            function<void(int, int, char)> dfs = [&](int x, int y, char c){
                                vis[x][y] = 1;
                                for(int d = 0; d < 4; d++){
                                    int nx = x + dir[d][0];
                                    int ny = y + dir[d][1];
                                    if(valid(nx,ny) && g[nx][ny] == c && !vis[nx][ny]){
                                        dfs(nx, ny, c);
                                    }
                                }
                            };
                            if(!vis[a][b]){
                                dfs(a, b, g[a][b]);
                                m[g[a][b]]++;
                            }
                        }
                    }
                    if(m.size() == 2){
                        vector<int> v;
                        for(auto x: m)
                            v.push_back(x.second);
                        sort(v.begin(), v.end());
                        if(v[0] == 1 && v[1] > 1)
                            ans.push_back({i, j, row, col});
                    }
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < ans.size(); i++){
        bool bad = 0;
        for(int j = 0; j < ans.size(); j++){
            if(i == j)
                continue;
            if(ans[i][0] >= ans[j][0] && ans[i][2] <= ans[j][2] && ans[i][1] >= ans[j][1] && ans[i][3] <= ans[j][3])
                bad = 1;
        }
        if(!bad)
            cnt++;
    }
    cout<<cnt<<"\n";
}
