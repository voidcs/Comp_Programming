#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 998244353;

int main(){
    ll n, m;
    cin>>n>>m;
    string a, b;
    cin>>a>>b;
    vector<ll> index;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i = 0; i < m; i++)
        if(b[i] == '1')
            index.push_back(i);
    auto expo_pow = [&](ll base, ll power){
        ll res = 1;
        while(power){
            if(power%2)
                res = (res * base) % mod;
            base = (base * base) % mod;
            power /= 2;
        }
        return res;
    };
    ll p = 1;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == '1'){
            ll x = index.end() - lower_bound(index.begin(), index.end(), i);
            //cout<<"x: "<<x<<endl;
            ans += (x * p) % mod;
        }
        p = (p*2) % mod;
        ans %= mod;
    }
    cout<<ans%mod<<endl;
    return 0;
}
