#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b, k;
        cin>>a>>b>>k;
        ll ans = ((k+1)/2) * a;
        ans -= (k/2) * b;
        cout<<ans<<endl;
    }
    return 0;
}
