//PROBLEM LINK
//https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        typedef long long ll;
        ll n = obstacleGrid.size();
        ll m = obstacleGrid[0].size();
        
        ll dp[n][m];
        dp[n-1][m-1] = obstacleGrid[n-1][m-1] ^ 1;
        
        for(int i = m-2; i >= 0; i--){
            if(obstacleGrid[n-1][i] == 1 || dp[n-1][i+1] == 0)
                dp[n-1][i] = 0;
            else
                dp[n-1][i] = 1;
        }
        
        for(int i = n-2; i >= 0; i--){
            if(obstacleGrid[i][m-1] == 1 || dp[i+1][m-1] == 0)
                dp[i][m-1] = 0;
            else
                dp[i][m-1] = 1;
        }
        
        for(int i = n-2; i >= 0; i--){
            for(int j = m-2; j >= 0; j--){
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};