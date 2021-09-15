//https://leetcode.com/problems/combination-sum/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& v, int target) {
        vector<vector<int>> ans;
        vector<int> have;
        function<void(int, int)> f = [&](int sum, int i){
            if(sum == target){
                ans.push_back(have);
                return;
            }
            for(int j = i; j < v.size(); j++){
                if(sum + v[j] <= target){
                    have.push_back(v[j]);
                    f(sum+v[j], j);
                    have.pop_back();
                }
            }
        };
        f(0, 0);
        return ans;
    }};