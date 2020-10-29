#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll ans;
        ll x, y;
        cin>>y>>x;
        ll z = max(x, y);
        ans = (z-1) * (z-1);
        if(x == z){
            if(x % 2){
                ans += (2*z);
                ans -= y;
            }
            else{
                ans += y;
            }
        }
        else if(y == z){
            if(y % 2){
                ans += x;
            }
            else{
                ans += (2*z);
                ans -= x;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}