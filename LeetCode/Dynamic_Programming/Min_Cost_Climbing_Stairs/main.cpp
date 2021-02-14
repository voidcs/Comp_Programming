//https://leetcode.com/problems/min-cost-climbing-stairs/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        int n = a.size();
        const int INF = 1e9;
        vector<int> dp(n+1, INF);
        dp[0] = dp[1] = 0;
        for(int i = 0; i < n; i++){
            dp[i+1] = min(dp[i+1], dp[i] + a[i]);
            if(i < n-1)
                dp[i+2] = min(dp[i+2], dp[i] + a[i]);
        }
        return dp[n];
    }
};