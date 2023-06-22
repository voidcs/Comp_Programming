#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int n;
    cin>>n;
    map<array<string, 2>, int> m;
    int ans = 0;
    for(int i = 0; i < n; i++){
        string x, y;
        cin>>x>>y;
        string a = string(1, x[0]) + x[1];
        if(m.count({y, a}) && y != a)
            ans += m[{y, a}];
        m[{a, y}]++;
    }
    cout<<ans<<endl;
    return 0;
}