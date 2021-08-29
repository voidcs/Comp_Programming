class Solution {
public:
    //https://leetcode.com/problems/two-sum/
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int need = target - nums[i];
            if(m.count(need)){
                return {i, m[need]};
            }
            m[nums[i]] = i;
        }
        return {-1, -1};
    }
};