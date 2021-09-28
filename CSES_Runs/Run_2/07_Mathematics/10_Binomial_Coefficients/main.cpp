#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll maxN = 1e6+5;
    vector<ll> f(maxN, 0);
    f[0] = f[1] = 1;
    for(int i = 2; i < maxN; i++){
        f[i] = (f[i-1]*i) % mod;
    }
    ll t;
    cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        function<ll(ll, ll, ll)> expo_pow = [&](ll base, ll power, ll m){
            ll res = 1;
            while(power){
                if(power%2){
                    res = (res * base)%mod;
                }
                power /= 2;
                base = (base*base) % mod;
            }
            return res;
        };
        if(b > a){
            cout<<"0\n";
            continue;
        }
        ll ans = f[a];
        
        ll x = (f[b]*(f[a-b]))%mod;
        ll inv = expo_pow(x, mod-2, mod);
        ans = (ans*inv) % mod;
        cout<<ans<<endl;
    }
    
    return 0;
}