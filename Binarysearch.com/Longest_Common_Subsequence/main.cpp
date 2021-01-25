int solve(string a, string b) {
    typedef long long ll;
    ll n = a.length(), m = b.length();
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}