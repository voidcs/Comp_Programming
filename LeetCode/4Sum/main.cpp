class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        typedef long ll;
        unordered_map<ll, ll> m;
        for(int x: nums){
            m[x]++;
        }
        int n = nums.size();
        vector<vector<int>> ans;
        set<vector<int>> s;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    ll have = 0LL + nums[i] + nums[j] + nums[k];
                    ll need = target - have;
                    m[nums[i]]--;
                    m[nums[j]]--;
                    m[nums[k]]--;
                    if(m.count(need) && m[need] > 0){
                        vector<int> v = {nums[i], nums[j], nums[k], (int)need};
                        sort(v.begin(), v.end());
                        if(!s.count(v)){
                            s.insert(v);
                            ans.push_back(v);
                        }
                    }
                    m[nums[i]]++;
                    m[nums[j]]++;
                    m[nums[k]]++;
                }
            }
        }
        return ans;
    }
};