#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    ll l = 0, r = 1e18;
    ll ans = -1;
    auto valid = [&](ll m){
        ll cnt = 1, sum = 0;
        for(ll x: v){
            if(x > m)
                return false;
            if(sum + x > m){
                cnt++;
                sum = x;
            }
            else{
                sum += x;
            }
        }
        return cnt <= k;
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
