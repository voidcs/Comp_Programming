#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x, y;
        cin>>y>>x;
        ll z = max(x, y);
        ll ans;
        if(x == y){
            ans = z*z;
            ans -= (x-1);
        }
        else if(x == z){
            if(x%2 == 1){
                ans = z*z;
                ans -= (y-1);
            }
            else{
                ans = (z-1)*(z-1);
                ans += y;
            }
        }
        else if(y == z){
            if(y%2 == 1){
                ans = (z-1)*(z-1);
                ans += x;
            }
            else{
                ans = z*z;
                ans -= x-1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
