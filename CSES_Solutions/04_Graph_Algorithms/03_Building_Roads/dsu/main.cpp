#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll> par(n+1);
    iota(par.begin(), par.end(), 0);
    
    function<int(int)> find = [&](int x){
        return (x == par[x]) ? x : par[x] = find(par[x]);
    };
    
    auto unite = [&](int x, int y){
        x = find(x), y = find(y);
        if(x != y)
            par[x] = par[y];
    };
    
    while(m--){
        ll a, b;
        cin>>a>>b;
        unite(a, b);
    }
    
    vector<array<ll, 2>> ans;
    for(int i = 1; i <= n; i++){
        int x = find(i);
        if(x != find(1)){
            par[x] = 1;
            ans.push_back({i, 1});
        }
    }
    cout<<ans.size()<<endl;
    for(auto x: ans)
        cout<<x[0]<<" "<<x[1]<<endl;
    
    return 0;
}