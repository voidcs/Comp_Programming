//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    //We don't need to store the entire dp table
    //We only need to keep track of the dp states for 2 less than the current length
    //Then we can get rid of the previous rows in our dp table
    //This brings the space complexity down to O(n)
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(2, vector<bool>(n+1));
        for(int i = 0; i <= n; i++)
            dp[0][i] = dp[1][i] = 1;
        string ans = string(1, s[0]);
        int longest = 1, index = 0;
        for(int i = 2; i <= n; i++){
            vector<bool> newDp(n+1);
            for(int j = 0; j <= n-i; j++){
                if(s[j] == s[j+i-1] && dp[0][j+1]){
                    newDp[j] = 1;
                    longest = i, index = j;
                }
            }
            dp[0] = dp[1];
            dp[1] = newDp;
        }
        return s.substr(index, longest);
    }
};