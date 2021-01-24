#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    for(ll i = 1; i <= n; i++){
        ll ans = ((i*i)*((i*i)-1))/2;
        if(n >= 3){
            ll sub = 4*(i-1)*(i-2);
            ans -= sub;
        }
        cout<<ans<<endl;
    }
    return 0;
}
