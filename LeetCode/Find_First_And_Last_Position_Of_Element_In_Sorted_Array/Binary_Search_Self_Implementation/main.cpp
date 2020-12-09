class Solution {
    //PROBLEM LINK
    //https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1, second = -1;
        int l = 0, r = n-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                first = mid;
                r = mid - 1;
            }
            else if(nums[mid] > target)
                r = mid-1;
            else
                l = mid+1;
        }
        l = 0, r = n-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] == target){
                second = mid;
                l = mid + 1;
            }
            else if(nums[mid] > target)
                r = mid-1;
            else
                l = mid+1;
        }
        if(first == -1)
            return {-1, -1};
        else
            return {first, second};
        
    }
};