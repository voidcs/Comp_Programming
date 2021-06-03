#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("cowqueue.in", "r", stdin);
    freopen("cowqueue.out", "w", stdout);
    int n;
    cin>>n;
    vector<array<int, 2>> v(n);
    for(auto &x: v)
        cin>>x[0]>>x[1];
    sort(v.begin(), v.end());
    int t = 0;
    for(int i = 0; i < n; i++){
        t = max(t, v[i][0]) + v[i][1];
    }
    cout<<t<<endl;
    return 0;
}