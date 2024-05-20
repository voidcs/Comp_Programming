class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a = s1.length();
        int b = s2.length();
        int c = s3.length();
        vector<vector<bool>> dp(a+1, vector<bool>(b+1));
        dp[0][0] = 1;
        if(a + b != c){
            return false;
        }
        // Let dp[a][b] be matching first a + b letters of s3
        for(int i = 0; i <= a; i++){
            for(int j = 0; j <= b; j++){
                if(i && s1[i-1] == s3[i+j-1] && dp[i-1][j]){
                    dp[i][j] = 1;
                }
                if(j && s2[j-1] == s3[i+j-1] && dp[i][j-1]){
                    dp[i][j] = 1;
                }
            }
        }
        return dp[a][b] && a + b == c;
        return true;
    }
};