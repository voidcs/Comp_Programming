//PROBLEM LINK
//https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
    
        int n = s.length();
        if(n == 0)
            return "";
        
        bool dp[n+1][n+1];
        string ans;
        ans += s[0];
        int maxLen = 1;
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++)
                dp[i][j] = 0;
        }
        for(int i = 0; i <= n; i++)
            dp[0][i] = dp[1][i] = 1;
        
        for(int i = 2; i <= n; i++){
            for(int j = i; j <= n; j++){
                if(s[j-1] == s[j-i] && dp[i-2][j-1]){
                    dp[i][j] = 1;
                    if(i > maxLen){
                        maxLen = i;
                        ans = s.substr(j-i, i);
                    }
                }
                else
                    dp[i][j] = 0;
            }
        }
        return ans;
    }
};