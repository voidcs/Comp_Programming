class Solution {
public:
    int minMoves(vector<int>& v) {
        sort(v.begin(), v.end());
        int ans = 0;
        for(int i = 1; i < v.size(); i++){
            ans += v[i] - v[0];
        }
        return ans;
    }
};