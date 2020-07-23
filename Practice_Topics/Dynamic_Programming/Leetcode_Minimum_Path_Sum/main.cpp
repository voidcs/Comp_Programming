//PROBLEM LINK
//https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
		//num rows
        int n = grid.size();
		//num cols
        int m = grid[0].size();
		
        int dp[n+1][m+1];
        int INF = INT_MAX;
		
		//Set bottom row to INF
        for(int i = 0; i < m; i++)
            dp[n][i] = INF;
		
        //Set right most col to INF
        for(int i = 0; i < n; i++)
            dp[i][m] = INF;
        
		//Set bottom and right cells of dp[n][m] to 0
        dp[n][m-1] = 0, dp[n-1][m] = 0;
		//Initialize the final cell cost
        dp[n-1][m-1] = grid[n-1][m-1];
		
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] += grid[i][j];
            }
        }
        return dp[0][0]; 
    }
};