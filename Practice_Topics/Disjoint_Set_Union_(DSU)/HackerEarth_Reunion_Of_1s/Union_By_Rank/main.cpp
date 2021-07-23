#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<int> cnt(n), par(n);
    iota(par.begin(), par.end(), 0);
    function<int(int)> find = [&](int x){
        return x == par[x] ? x : par[x] = find(par[x]);
    };
    auto unite = [&](int x, int y){
        x = find(x), y = find(y);
        if(x != y){
            if(cnt[x] > cnt[y])
                swap(x, y);
            cnt[y] += cnt[x];
            par[x] = y;
        }
    };
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1')
            cnt[i] = 1;
    }
    for(int i = 1; i < n; i++){
        if(s[i] == '1' && s[i-1] == '1'){
            unite(i, i -1);
        }
        ans = max(ans, cnt[find(i)]);
    }
    while(q--){
        int op;
        cin>>op;
        if(op == 1){
            cout<<ans<<endl;
        }
        else{
            int x;
            cin>>x;
            x--;
            if(s[x] == '0')
                cnt[x] = 1;
            s[x] = '1';
            if(x-1 >= 0 && s[x-1] == '1'){
                unite(x, x - 1);
            }
            if(x+1 < n && s[x+1] == '1'){
                unite(x, x + 1);
            }
            ans = max(ans, cnt[find(x)]);
        }
    }
    return 0;
}