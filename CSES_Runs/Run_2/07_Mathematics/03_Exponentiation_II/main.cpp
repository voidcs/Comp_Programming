#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b, c;
        cin>>a>>b>>c;
        function<ll(ll, ll, ll)> expo_pow = [&](ll base, ll power, ll m){
            ll res = 1;
            while(power){
                if(power%2){
                    res = (res*base)%m;
                }
                base = (base*base)%m;
                power /= 2;
            }
            return res;
        };
        ll BtoC = expo_pow(b, c, mod-1);
        cout<<expo_pow(a, BtoC, mod)<<endl;
    }
    
    return 0;
}