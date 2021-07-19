#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    ll lowest = 0, sum = 0, ans = -INF;
    for(ll x: v){
        sum += x;
        ans = max(ans, sum - lowest);
        lowest = min(lowest, sum);
    }
    cout<<ans<<endl;
    return 0;
}
