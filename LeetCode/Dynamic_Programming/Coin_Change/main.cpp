class Solution {
    //PROBLEM LINK
    //https://leetcode.com/problems/coin-change/
    
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        long long INF = 1e18;
        vector<long long> dp(amount+1, INF);
        dp[0] = 0;
        for(int i = 0; i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(coins[j] <= i)
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        if(dp[amount] == INF)
            return -1;
        else
            return dp[amount];
    }
};