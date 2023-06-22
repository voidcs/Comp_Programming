#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

int main(){
    ll n;
    cin>>n;
    ll ans = 0;
    unordered_map<ll, ll> m;
    for(ll i = 2; i*i <= n; i++){
        while(n % i == 0){
            m[i]++;
            n /= i;
        }
    }
    if(n != 1)
        m[n]++;
    for(auto [factor, cnt]: m){
        ll inc = 1;
        ll x = 0;
        while(x+inc <= cnt){
            x += inc++;
            ans++;
        }
    }
    cout<<ans<<"\n";
}
