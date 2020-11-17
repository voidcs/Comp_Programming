#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = INT_MAX;

int main(){
    string a, b;
    cin>>a>>b;
    int n = a.length();
    int m = b.length();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++)
        dp[i][0] = i;
    for(int i = 1; i <= m; i++)
        dp[0][i] = i;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = INF;
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1];
            dp[i][j] = min({dp[i][j]-1, dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}