//https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    int climbStairs(int n) {
        typedef long long ll;
        array<ll, 2> dp = {1, 2};
        for(int i = 0; i < n-1; i++){
            array<ll, 2> newDp;
            newDp[0] = dp[1];
            newDp [1] = dp[0] + dp[1];
            dp = newDp;
        }
        return dp[0];
    }
};