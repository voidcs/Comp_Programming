#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll c = 0;
    ll ans = 0;
    while(n--){
        ll a, b;
        cin>>a>>b;
        c -= a;
        c += b;
        ans = max(ans, c);
    }
    cout<<ans<<endl;
    return 0;
}