class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 1e9, closest = 1e9;
        for(int i = 0; i < n; i++){
            int l = i + 1, r = n-1;
            while(l < r){
                int have = nums[i] + nums[l] + nums[r];
                if(abs(target - have) < closest){
                    closest = abs(target - have);
                    ans = have;
                }
                if(abs(target - (nums[i] + nums[l+1] + nums[r])) < abs(target - (nums[i] + nums[l] + nums[r]))){
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return ans;
    }
};