#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        function<ll(ll, ll)> expo_pow = [&](ll base, ll power){
            ll res = 1;
            while(power){
                if(power%2){
                    res = (res*base)%mod;
                }
                base = (base*base)%mod;
                power /= 2;
            }
            return res;
        };
        cout<<expo_pow(a, b)<<endl;
    }
    
    return 0;
}