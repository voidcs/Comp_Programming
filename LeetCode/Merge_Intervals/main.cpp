class Solution {
    //PROBLEM LINK
    //https://leetcode.com/problems/merge-intervals/
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        vector<vector<int>> ans;
        int n = a.size();
        sort(a.begin(), a.end());
        int start = a[0][0], end = a[0][1];
        for(int i = 1; i < n; i++){
            if(a[i][0] > end){
                ans.push_back({start, end});
                start = a[i][0], end = a[i][1];
            }
            end = max(end, a[i][1]);
        }
        ans.push_back({start, end});
        return ans;
    }
};