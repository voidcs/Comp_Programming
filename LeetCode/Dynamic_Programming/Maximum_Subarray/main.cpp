//https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n = a.size();
        const int INF = 1e9;
        int ans = -INF, sum = 0;
        for(int i = 0; i < n; i++){
            sum = max(sum + a[i], a[i]);
            ans = max(ans, sum);
        }
        return ans;
    }
};