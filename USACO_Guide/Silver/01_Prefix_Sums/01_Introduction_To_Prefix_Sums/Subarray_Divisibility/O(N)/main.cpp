#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n), m(n);
    m[0]++;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        sum = (sum + (v[i]%n+n)) % n;
        m[sum]++;
    }
    ll ans = 0;
    for(auto x: m){
        ans += (x * (x-1)) / 2;
    }
    cout<<ans<<endl;
    return 0;
}
