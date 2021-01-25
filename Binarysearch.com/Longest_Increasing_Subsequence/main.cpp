int solve(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n+1, 1);
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(a[j-1] > a[i-1])
                dp[j] = max(dp[j], dp[i]+1);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }
    return ans;
}