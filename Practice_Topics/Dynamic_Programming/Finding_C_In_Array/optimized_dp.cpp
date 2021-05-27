#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<vector<char>> v(n, vector<char>(m));
    int dp[n][m][m+1][n+1][m+1];
    for(int a = 0; a < n; a++)
        for(int b = 0; b < m; b++)
            for(int c = 0; c <= m; c++)
                for(int d = 0; d <= n; d++)
                    for(int e = 0; e <= m; e++)
                        dp[a][b][c][d][e] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>v[i][j];
        }
    }
    // cout<<n<<" "<<m<<endl;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout<<v[i][j];
    //     }
    //     cout<<endl;
    // }

    //If line[i][j][k] = 1, there is a k-1 len line starting at (i+1, j)
    vector<vector<vector<bool>>> line(n, vector<vector<bool>>(m, vector<bool>(n+1)));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int h = 3; i + h <= n; h++){
                auto valid = [&](int x, int y){
                    return x >= 0 && x < n && y >= 0 && y < m && v[x][y] == '.';
                };
                auto baseCase = [&](){
                    //If h > 3, we don't have to reiterate, check if there was a line of
                    //length h-1 and then see if we can go down one more
                    if(h > 3){
                        //Update line of length h
                        if(i+h-1 < n && line[i][j][h-1] && v[i+h-1][j] == '.')
                            line[i][j][h] = 1;
                        if(!valid(i+h-1, j+1))
                            return false;
                        bool x = line[i][j][h-1] && v[i][j] == '.' && v[i][j+1] == '.' && v[i+h-1][j] == '.' && v[i+h-1][j+1] == '.';
                        return x;
                    }
                    //Update arrays for smallest possible size C
                    bool ok = 1, lineOk = 1;
                    for(int a = 0; a < 2; a++)
                        ok &= valid(i, j+a);
                    for(int b = 1; b < h; b++){
                        ok &= valid(i+b, j);
                        lineOk &= valid(i+b, j);
                    }
                    for(int c = 0; c < 2; c++)
                        ok &= valid(i+h-1, j+c);
                    if(lineOk)
                        line[i][j][h] = 1;
                    return ok;
                };
                if(baseCase()){
                    dp[i][j][2][h][2] = 1;
                } 
                else
                    continue;
                //Try to create another C by extending the top horizontal part
                for(int w2 = 2; j + w2 <= m; w2++){
                    for(int w1 = 3; j + w1 <= m; w1++){
                        if(dp[i][j][w1-1][h][w2] == 1 && v[i][j+w1-1] == '.')
                            dp[i][j][w1][h][w2] = 1;
                    }
                }     
                //Try to create another C by extending the bottom horizontal part
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
                        if(dp[i][j][w1][h][w2] == 1){
                            ans++;
                            //cout<<"i:" <<i<<"  j: "<<j<<"  w1: "<<w1<<"  h: "<<h<<"  w2: "<<w2<<"\n";
                        }
                    }
                }
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}