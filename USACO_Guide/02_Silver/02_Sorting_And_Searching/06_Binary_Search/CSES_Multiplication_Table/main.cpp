#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    ll l = 0, r = 1e18;
    ll ans = -1;
    ll i = (n*n) / 2; //We need i elements to be <= to us
    auto valid = [&](ll m){
        ll sum = 0;
        for(ll x = 1; x <= n; x++){
            sum += min(m / x, n);
        }
        return sum > i;
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
