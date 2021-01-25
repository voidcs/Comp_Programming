int solve(vector<int>& a) {
    unordered_map<int, int> m;
    int ans = 0;
    int n = a.size();
    for(int i = 0; i < n; i++){
        m[a[i]]++;
        ans += m[a[i]];
    }
    
    return ans;
}