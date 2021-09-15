//https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int j = 0;
        bool search = true;
        while(search){
            bool ok = true;
            for(int i = 0; i < strs.size(); i++){
                if(j >= strs[i].length() || (j < strs[i].length() && strs[i][j] != strs[0][j]))
                    ok = false;
            }
            if(ok)
                ans += strs[0][j], j++;
            else
                search = false;
        }
        return ans;
    }
};