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
    string s;
    cin>>s;
    ll n = s.length();
    map<char, ll> m;
    for(int i = 0; i < n; i++){
        m[s[i]]++;
    }
    ll ans = f[n];
    function<ll(ll, ll, ll)> expo_pow = [&](ll base, ll power, ll mod){
        ll res = 1;
        while(power){
            if(power%2)
                res = (res*base)%mod;
            power /= 2;
            base = (base*base)%mod;
        }
        return res;
    };
    for(auto x: m){
        ll freq = x.second;
        ll ways = f[freq];
        ll inv = expo_pow(ways, mod-2, mod);
        ans = (ans*inv)%mod;
    }
    cout<<ans<<endl;
    
    return 0;
}