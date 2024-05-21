class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        int l = 1, r = 1e9;
        int ans = -1;
        auto valid = [&](int health){
            vector<vector<int>> dp(n, vector<int>(m, -1e9));  // maximum hp that we have at 
            dp[0][0] = health + dungeon[0][0];
            if(dungeon[0][0] + health <= 0){
                return false;
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(i && dp[i-1][j] + dungeon[i][j] > 0){
                        dp[i][j] = max(dp[i][j], dp[i-1][j] + dungeon[i][j]);
                    }
                    if(j && dp[i][j-1] + dungeon[i][j] > 0){
                        dp[i][j] = max(dp[i][j], dp[i][j-1] + dungeon[i][j]);
                    }
                }
            }

            return dp[n-1][m-1] >= 0;
        };
        while(l <= r){
            int m = (l + r) / 2;
            if(valid(m)){
                ans = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        } 
        return ans;
    }
};