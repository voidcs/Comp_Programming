class Solution {
public:
    //PROBLEM LINK
    //https://leetcode.com/problems/two-sum/
    vector<int> twoSum(vector<int>& nums, int target) {
        typedef long long ll;
        map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++)
            m[nums[i]] = i;
        
        for(int i = 0; i < n; i++){
            int need = target - nums[i];
            if(m.count(need) && m[need] != i){
                return {i, m[need]};
            }
        }
        return {-1, -1};
    }
};