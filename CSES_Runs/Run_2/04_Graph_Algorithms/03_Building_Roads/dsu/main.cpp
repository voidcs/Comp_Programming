#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector<int> par(n+1);
    iota(par.begin(), par.end(), 0);
    function<int(int)> find = [&](int x){
        return (x == par[x]) ? x : par[x] = find(par[x]);
    };
    
    function<void(int, int)> unite = [&](int x, int y){
        x = find(x), y = find(y);
        if(x != y){
            par[x] = y;
        }
    };
    
    while(m--){
        int a, b;
        cin>>a>>b;
        unite(a, b);
    }
    vector<array<int, 2>> ans;
    for(int i = 2; i <= n; i++){
        if(find(i) != find(1)){
            unite(1, i);
            ans.push_back({1, i});
        }
    }
    cout<<ans.size()<<endl;
    for(auto x: ans){
        cout<<x[0]<<" "<<x[1]<<endl;
    }
    
    
    return 0;
}