#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<vector<char>> v(n, vector<char>(m));
    int dp[n][m][n+1][m+1][n+1];
    for(int a = 0; a < n; a++)
        for(int b = 0; b < m; b++)
            for(int c = 0; c <= n; c++)
                for(int d = 0; d <= m; d++)
                    for(int e = 0; e <= n; e++)
                        dp[a][b][c][d][e] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>v[i][j];
        }
    }
    cout<<n<<" "<<m<<endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int h = 3; i + h <= n; h++){
                auto valid = [&](int x, int y){
                    return x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '.';
                };
                auto baseCase = [&](){
                    bool ok = 1;
                    for(int a = 0; a < 2; a++)
                        ok &= valid(i, j+a);
                    for(int b = 0; b < h; b++)
                        ok &= valid(i+b, j);
                    for(int c = 0; c < 2; c++)
                        ok &= valid(i+h-1, j+c);
                    return ok;
                };
                if(baseCase()){
                    dp[i][j][2][h][2] = 1;
                }
                else
                    continue;
                for(int w2 = 2; j + w2 <= m; w2++){
                    for(int w1 = 3; j + w1 <= m; w1++){
                        if(dp[i][j][w1-1][h][w2] == 1 && v[i][j+w1-1] == '.')
                            dp[i][j][w1][h][w2] = 1;
                    }
                }     
                for(int w1 = 2; j + w1 <= m; w1++){
                    for(int w2 = 3; j + w2 <= m; w2++){
                        if(dp[i][j][w1][h][w2-1] == 1 && v[i+h-1][j+w2-1] == '.')
                            dp[i][j][w1][h][w2] = 1;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int w1 = 0; w1 <= m; w1++){
                for(int h = 0; h <= n; h++){
                    for(int w2 = 0; w2 <= m; w2++){
                        if(dp[i][j][w1][h][w2]){
                            ans++;
                            cout<<"i:" <<i<<"  j: "<<j<<"  w1: "<<w1<<"  h: "<<h<<"  w2: "<<w2<<"\n";
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}