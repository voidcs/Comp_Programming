int solve(vector<vector<int>>& intervals) {
    if(intervals.size() == 0)
        return 0;
    sort(intervals.begin(), intervals.end());
    int end = 0, seg = 0, start = 0, ans = 0;
    for(int i = 0; i < intervals.size(); i++){
        if(intervals[i][0] <= end){
            seg = max(intervals[i][1], end) - start + 1;
            end = max(end, intervals[i][1]);
        }
        else{
            start = intervals[i][0];
            end = intervals[i][1];
            seg = intervals[i][1] - intervals[i][0]+1;
        }
        ans = max(ans, seg);
    }
    return ans;
}