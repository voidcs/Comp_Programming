//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n+1, 0);
        const int INF = 1e9;
        int m = INF;
        for(int i = 0; i < n; i++){
            dp[i+1] = max(dp[i+1], a[i] - m);
            m = min(m, a[i]);
        }
        int ans = 0;
        for(int i = 0; i <= n; i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};