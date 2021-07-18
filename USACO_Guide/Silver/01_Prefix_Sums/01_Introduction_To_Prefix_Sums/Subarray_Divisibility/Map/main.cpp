#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);
    ll n;
    cin>>n;
    vector<ll> v(n);
    map<ll, ll> m;
    m[0] = 1;
    ll ans = 0, sum = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        //Make sure to add n back for negative numbers
        sum = (sum + (v[i]%n) + n) % n;
        if(m.count(sum))
            ans += m[sum];
        m[sum]++;
    }
    cout<<ans<<endl;
    return 0;
}
