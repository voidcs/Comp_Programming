
//PROBLEM LINK
//https://leetcode.com/problems/coin-change/submissions/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        long long dp[amount+1];
        long long INF = 10e10;
        for(int i = 0; i <= amount; i++)
            dp[i] = INF;
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(auto x: coins){
                if(x <= i){
                    dp[i] = min(dp[i], dp[i-x]+1);
                }
            }
        }
        if(dp[amount] == INF)
            return -1;
        return dp[amount];
        
    }
};