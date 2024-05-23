class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < (1<<n); i++){
            int m = 0;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    m++;
                }
            }
            if(m == 0){
                continue;
            }
            int index = 0;
            int v[m];
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    v[index] = nums[j];
                    index++;
                }
            }
            bool ok = 1;
            int l = 0, r = 0;
            while(r < m){
                while(v[r] - v[l] > k){
                    l++;
                }
                if(v[r] - v[l] == k){
                    ok = 0;
                    break;
                }
                r++;
            }
            if(ok){
                ans++;
            }
        }
        return ans;
    }
};