class Solution {
public:
    //https://leetcode.com/problems/longest-substring-without-repeating-characters/
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), l = 0;
        int ans = 0;
        map<char, int> cnt;
        for(int r = 0; r < n; r++){
            cnt[s[r]]++;
            while(cnt[s[r]] > 1){
                cnt[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};