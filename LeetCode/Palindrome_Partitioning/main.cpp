class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> p(n);
        vector<vector<string>> ans;
        function<void(int, int)> f = [&](int i, int j){
            if(i == n){
                bool is_palindrome = 1;
                for(auto x: p){
                    if(x.length() == 0)
                        continue;
                    string rev = x;
                    reverse(rev.begin(), rev.end());
                    if(rev != x){
                        is_palindrome = 0;
                    }
                }
                if(is_palindrome){
                    vector<string> temp;
                    for(auto x: p){
                        if(x.length()){
                            temp.push_back(x);
                        }
                    }
                    ans.push_back(temp);
                }
                return;
            }
            p[j] += s[i];
            f(i+1, j);
            p[j].pop_back();
            if(p[j].length() > 0){
                j++;
                p[j] += s[i];
                f(i+1, j);
                p[j].pop_back();
            }
        };
        f(0, 0);
        return ans;
    }
};