#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> par(n+1);
    iota(par.begin(), par.end(), 0);
    function<int(int)> find = [&](int x){
        return (x == par[x]) ? x : par[x] = find(par[x]);
    };
    auto unite = [&](int x, int y){
        x = find(x);
        y = find(y);
        if(x != y)
            par[y] = x;
    };
    while(m--){
        int a, b;
        cin>>a>>b;
        unite(a, b);
    }
    vector<int> ans;
    for(int i = 2; i <= n; i++){
        if(i == find(i) && find(i) != find(1))
            ans.push_back(i);
    }
    cout<<ans.size()<<"\n";
    for(auto x: ans)
        cout<<"1 "<<x<<"\n";
} 
