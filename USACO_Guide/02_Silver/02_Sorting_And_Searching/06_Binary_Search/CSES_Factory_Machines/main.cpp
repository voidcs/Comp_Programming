#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, t;
    cin>>n>>t;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    ll l = 0, r = 1e18;
    ll ans = -1;
    auto valid = [&](ll m){
        ll sum = 0;
        for(auto x: v){
            sum += m / x;
            if(sum >= t)
                return true;
        }
        return sum >= t;
    };
    while(l <= r){
        ll m = (l + r) / 2;
        if(valid(m)){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    cout<<ans<<"\n";
} 
