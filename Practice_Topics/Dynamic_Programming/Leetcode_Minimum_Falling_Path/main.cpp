//PROBLEM LINK
//https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        //n is size of vector for convenience
        int n = A.size();
        int dp[n][n];
        
        //Initialize bottom row of dp array to values of the array
        for(int i = 0; i < n; i++){
            dp[n-1][i] = A[n-1][i];
        }
        
        //Start from second bottom row of dp array
        for(int i = n-2; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                
                int curr = 1e4;
                
                //Take min of cell below
                curr = min(curr, dp[i+1][j]);
                
                //Take min of cell bottom left
                if(j > 0)
                    curr = min(curr, dp[i+1][j-1]);
                
                //Take min of cell bottom right
                if(j < n-1)
                    curr = min(curr, dp[i+1][j+1]);
                
                //Add the cost of visting this cell
                curr += A[i][j];
                dp[i][j] = curr;
            }
        }
        
        int ans = 1e6;
        //Iterate through top row to find shortest cost to bottom row
        for(int i = 0; i < n; i++){
            ans = min(ans, dp[0][i]);
        }
        
        return ans;
    }
};