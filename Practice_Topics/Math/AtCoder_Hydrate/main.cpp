#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    ll a, b, c, d;
    cin>>a>>b>>c>>d;
    ll x = (b-(c*d));
    if(x == 0){
        cout<<"-1\n";
        return 0;
    }
    ll ans = (-a + x + 1) / x;
    if(ans <= 0)
        cout<<"-1\n";
    else
        cout<<ans<<endl;
    return 0;
}