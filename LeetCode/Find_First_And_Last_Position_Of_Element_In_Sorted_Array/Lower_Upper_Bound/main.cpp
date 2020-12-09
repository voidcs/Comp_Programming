class Solution {
    //PROBLEM LINK
    //https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int b = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        b--;
        if(a < 0 || a >= nums.size() || nums[a] != target)
            return {-1, -1};
        return {a, b};
    }
};