int solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[n-1][m-1] = matrix[n-1][m-1];
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(i+1 < n)
                dp[i][j] = max(dp[i][j], matrix[i][j] + dp[i+1][j]);
            if(j+1 < m)
                dp[i][j] = max(dp[i][j], matrix[i][j] + dp[i][j+1]);
        }
    }
    return dp[0][0];
}