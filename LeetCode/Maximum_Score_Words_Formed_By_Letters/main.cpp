class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<vector<int>> subset; // How many of each character is needed to make each subset
        int n = words.size();
        int m = letters.size();
        for(int i = 0; i < (1<<n); i++){
            vector<int> cnt(26);
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    for(char c: words[j]){
                        cnt[c-'a']++;
                    }
                }
            }
            subset.push_back(cnt);
        }
        // For every single letter, sort their most valuable letters
        vector<int> cnt(26);
        for(char c: letters){
            cnt[c-'a']++;
        }
        int ans = 0;
        for(auto v: subset){
            bool ok = 1;
            int sum = 0;
            for(int i = 0; i < 26; i++){
                ok &= (v[i] <= cnt[i]);
                sum += v[i] * score[i];
            }
            if(ok){
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};