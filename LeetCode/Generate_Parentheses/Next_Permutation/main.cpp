class Solution {
    //PROBLEM LINK
    //https://leetcode.com/problems/generate-parentheses/submissions/
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        vector<int> r (n*2);
        for(int i = 0; i < n*2; i++){
            if(i < n)
                r[i] = 0;
            else
                r[i] = 1;
        }
        do{
            string str;
            for(int i = 0; i < 2*n; i++){
                if(r[i])
                    str += ')';
                else
                    str += '(';
            }
            int bal = 0;
            bool valid = 1;
            for(int i = 0; i < 2*n; i++){
                if(str[i] == ')')
                    bal--;
                else
                    bal++;
                if(bal < 0)
                    valid = 0;
            }
            if(valid)
                ans.push_back(str);
        }while(next_permutation(r.begin(), r.end()));
        
        return ans;
    }
};