class Solution {
    typedef long long ll;
    //PROBLEM LINK
    //https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
public:
    int minDifficulty(vector<int>& a, int d) {
        int n = a.size();
        const ll INF = 1e18;
        vector<vector<ll>> dp(n+1, vector<ll>(d+1, INF));
        dp[0][0] = 0;
        for(int i = 0; i < n; i++){
            //Days represents the number of intervals 
            for(int days = 0; days <= d-1; days++){
                if(dp[i][days] == INF)
                    continue;
                ll max_in_interval = a[i];
                for(int j = i; j < n; j++){
                    max_in_interval = max(max_in_interval, (ll)a[j]);
                    //Interval from i-j
                    dp[j+1][days+1] = min(dp[j+1][days+1], dp[i][days] + max_in_interval);
                }
            }
        }
        if(dp[n][d] == INF)
            return -1;
        else
            return dp[n][d];
    }
};