class Solution {
    //PROBLEM LINK
    //https://leetcode.com/problems/generate-parentheses/submissions/
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        for(int i = 0; i < (1<<(2*n)); i++){
            string str;
            for(int j = 0; j < 2*n; j++){
                if(i & (1<<j))
                    str += '(';
                else
                    str += ')';
            }
            int bal = 0;
            bool valid = 1;
            for(int i = 0; i < str.length(); i++){
                if(str[i] == ')')
                    bal--;
                else
                    bal++;
                if(bal < 0)
                    valid = 0;
            }
            valid &= (bal == 0);
            if(valid)
                ans.push_back(str);
        }
        return ans;
    }
};