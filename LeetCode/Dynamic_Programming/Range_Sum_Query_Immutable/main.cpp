//https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
    
private:
    vector<int> p;
public:
    NumArray(vector<int>& nums) {
        p = nums;
        int n = nums.size();
        p = vector<int>(n+1);
        for(int i = 0; i < n; i++)
            p[i+1] += p[i]+nums[i];
    }
    
    int sumRange(int i, int j) {
        return p[j+1] - p[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */