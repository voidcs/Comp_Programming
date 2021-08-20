#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, radius;
    cin>>n>>radius;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    ll ans = 0, l = 0;
    for(int r = 0; r < n; r++){
        while(l + 1 < n && v[r] - v[l+1] > radius)
            l++;
        if(v[r] - v[l] > radius)
            ans += l+1;
    }
    cout<<ans<<endl;
    return 0;
}
