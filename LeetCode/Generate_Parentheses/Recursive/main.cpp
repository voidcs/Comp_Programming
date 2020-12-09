class Solution {
    //PROBLEM LINK
    //https://leetcode.com/problems/generate-parentheses/submissions/
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function<void(int, int, int, string)> cnt = [&](int a, int b, int bal, string s){
            if(s.length() == 2*n){
                ans.push_back(s);
                return;
            }
            if(bal > 0){
                if(b){
                    cnt(a, b-1, bal-1, s + ')');
                }
            }
            if(a){
                cnt(a-1, b, bal+1, s + '(');
            }
        };
        cnt(n, n, 0, "");
        return ans;
    }
};