//https://leetcode.com/problems/divisor-game/
class Solution {
public:
    bool divisorGame(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j*j < i; j++){
                //if this factor i, then Alice can play it
                //If Alice loses at dp[i-j], then this flips the situation
                //where she would lose and hands the loss to Bob
                if(i%j == 0 && dp[i-j] == 0)
                    dp[i] = 1;
            }
        }
        return dp[n];
    }
};