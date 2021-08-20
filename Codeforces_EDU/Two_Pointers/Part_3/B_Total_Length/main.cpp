#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, s;
    cin>>n>>s;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    ll ans = 0, l = 0, sum = 0;
    for(int r = 0; r < n; r++){
        sum += v[r];
        while(sum > s)
            sum -= v[l++];
        ll x = r - l + 1;
        ans += (x*(x+1))/2;
    }
    cout<<ans<<endl;
    return 0;
}
