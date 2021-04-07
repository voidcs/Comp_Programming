#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans = -1;
        for(int i = 2; i < 30; i++){
            ll x = (1LL<<i) - 1;
            if(n%x == 0){
                ans = n/x;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}