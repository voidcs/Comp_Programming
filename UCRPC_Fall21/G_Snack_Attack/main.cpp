#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    int n, p, b;
    cin>>n>>p>>b;
    vector<vector<int>> dp(n, vector<int>(n));
    int sx, sy;
    cin>>sx>>sy;
    vector<array<int, 4>> v;
    int totalTime = 0;
    for(int i = 0; i < p; i++){
        int x, y, z;
        cin>>x>>y>>z;
        totalTime = max(totalTime, z);
        v.push_back({z, x, y, 1});
    }
    for(int i = 0; i < b; i++){
        int x, y, z;
        cin>>x>>y>>z;
        totalTime = max(totalTime, z);
        v.push_back({z, x, y, 0});
    }
    int all = v.size();
    sort(v.begin(), v.end());
    array<int, 2> dir[4] = {{0, 1} ,{1, 0}, {-1, 0}, {0, -1}};
    auto valid = [&](int x, int y){
        return x >= 0 && x < n && y >= 0 && y < n;
    };
    int index = 0;
    for(int time = 1; time <= totalTime; time++){
        vector<vector<int>> newDp = dp;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(abs(sx-i) + abs(sy-j) > time)
                    continue;
                for(int d = 0; d < 4; d++){
                    int nx = i + dir[d][0];
                    int ny = j + dir[d][1];
                    if(valid(nx, ny)){
                        if(abs(nx-i) + abs(ny-j) > time)
                            continue;
                        if(newDp[i][j] < dp[nx][ny]){
                            newDp[i][j] = dp[nx][ny];
                        }
                    }
                }
            }
        }
        while(index < all && v[index][0] == time){
            int x = v[index][1], y = v[index][2];
            if(v[index][3] && abs(x-sx) + abs(y-sy) <= time){
                newDp[x][y]++;
            }
            else
                newDp[x][y] /= 2;
            index++;
        }
        dp = newDp;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans = max(ans, dp[i][j]);
    cout<<ans<<endl;
    
    return 0;
}