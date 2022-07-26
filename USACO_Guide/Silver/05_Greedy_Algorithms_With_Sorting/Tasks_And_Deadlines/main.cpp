#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    vector<array<ll, 2>> v(n);
    for(auto &x: v)
        cin>>x[0]>>x[1];
    sort(v.begin(), v.end(), [&](array<ll, 2> a, array<ll, 2> b){
            return a[0] < b[0];
            });
    ll time = 0, ans = 0;
    for(int i = 0; i < n; i++){
        time += v[i][0];
        ans += v[i][1] - time;
    }

    cout<<ans<<"\n";
}
