//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1));
        for(int i = 0; i <= n; i++)
            dp[0][i] = dp[1][i] = 1;
        string ans = string(1, s[0]);
        int longest = 1, index = 0;
        for(int i = 2; i <= n; i++){
            for(int j = 0; j <= n-i; j++){
                if(s[j] == s[j+i-1] && dp[i-2][j+1]){
                    dp[i][j] = 1;
                    longest = i, index = j;
                }
            }
        }
        return s.substr(index, longest);
    }
};