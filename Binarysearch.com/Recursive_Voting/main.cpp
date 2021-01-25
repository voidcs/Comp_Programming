int solve(vector<int>& a) {
    int n = a.size();
    if(a.size() == 0)
        return 0;

    vector<int> cnt(n+3, 0);
    vector<int> par(n+3);
    iota(par.begin(), par.end(), 0);
    function<int(int)> find = [&](int x){
        return (x==par[x]) ? x : par[x] = find(par[x]);
    };
    function<void(int, int)> unite = [&](int x, int y){
        x = find(x), y = find(y);
        if(x != y){
            if(x < y)
                swap(x, y);
            par[y] = x;
            cnt[x] += cnt[y];
        }
    };
    for(int i = 0; i < n; i++){
        if(a[i] >= 0 && a[i] < n)
            cnt[i] = 1;
        else
            cnt[i] = 0;
    }
    int extra = 0;
    for(int i = 0; i < n; i++){
        if(a[i] >= 0 && a[i] < n)
            unite(i, a[i]);
        if(a[i] < 0){
            extra++;
            unite(i, n+1);
        }
    }
    return cnt[n+1] + extra;
}