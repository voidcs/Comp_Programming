#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x, k, l, r;
        cin>>x>>k>>l>>r;
        ll ans = x/k;
        ll d = r-l;
        l = ((k-(l%k))%k) + l;
        r = r - (r%k);
        ans -= ((r-l)/k)+1;
        cout<<ans<<endl;
    }
    return 0;
}
