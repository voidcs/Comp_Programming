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
    map<map<ll, ll>, ll> m;
    ll ans = 0;
    for(ll x: v){
        map<ll, ll> factors;
        for(ll i = 2; i*i <= x; i++){
            int cnt = 0;
            while(x % i == 0){
                cnt++;
                x /= i;
            }
            if(cnt % k){
                factors[i] = cnt % k;
            }
        }
        if(x != 1)
            factors[x]++;
        map<ll, ll> compliment;
        for(auto &x: factors){
            if(x.second % k){
                compliment[x.first] = k - (x.second % k);
            }
        }
        ans += m[compliment];
        m[factors]++;
    }
    cout<<ans<<"\n";
    return 0;
}