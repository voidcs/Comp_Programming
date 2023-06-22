#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++)
        cin>>v[i];
    vector<array<int, 3>> wormholes(m);
    for(auto &x: wormholes){
        cin>>x[1]>>x[2]>>x[0];
    }
    sort(wormholes.begin(), wormholes.end());
    if(is_sorted(v.begin(), v.end())){
        cout<<"-1\n";
        return 0;
    }
    auto valid = [&](int mid){
        vector<int> par(n+1, -1);
        function<int(int)> find = [&](int x){
            return (par[x] < 0) ? x : par[x] = find(par[x]);
        };
        auto unite = [&](int x, int y){
            x = find(x);
            y = find(y);
            if(par[x] > par[y])
                swap(x, y);
            if(x != y){
                par[y] = x;
            }
        };
        for(int i = 0; i < m; i++){
            if(wormholes[i][0] >= mid){
                unite(v[wormholes[i][1]], v[wormholes[i][2]]);
            }
        }
        bool ok = 1;
        for(int i = 1; i <= n; i++){
            if(find(i) != find(v[i]))
                ok = 0;
        }
        return ok;
    };
    int ans = 0;
    int l = 0, r = 1e9;
    while(l <= r){
        int m = (l+r)/2;
        if(valid(m)){
            l = m+1;
            ans = m;
        }
        else
            r = m-1;
    }
    cout<<ans<<endl;
    return 0;
}
