#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n, k;
    cin>>n>>k;
    map<char, vector<vector<int>>> dp;
    for(char c: {'H', 'P', 'S'}){
        dp[c] = vector<vector<int>>(n+1, vector<int>(k+1));
    }
    map<char, char> m;
    m['H'] = 'S';
    m['P'] = 'H';
    m['S'] = 'P';
    for(int i = 1; i <= n; i++){
        char x;
        cin>>x;
        for(char c: {'H', 'P', 'S'}){
            for(int j = 0; j <= k; j++){
                if(m[c] == x)
                    dp[c][i][j] = max(dp[c][i][j], dp[c][i-1][j] + 1);
                else
                    dp[c][i][j] = max(dp[c][i][j], dp[c][i-1][j]);
            }
            for(int j = 1; j <= k; j++){
                for(char y: {'H', 'P', 'S'}){
                    if(c != y){
                        if(m[c] == x)
                            dp[c][i][j] = max(dp[c][i][j], dp[y][i-1][j-1]+1);
                    }
                }
            }
        }
    }
    int ans = 0;
    for(char c: {'H', 'P', 'S'}){
        ans = max(ans, dp[c][n][k]);
    }
    cout<<ans<<endl;
    return 0;
}
