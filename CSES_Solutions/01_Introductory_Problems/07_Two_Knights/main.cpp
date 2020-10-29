#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        ll total = i*i;
        ll ans = (total)*(total-1)/2;
        if(n >= 3)
            ans -= 4 * (i-1) * (i-2);
        cout<<ans<<endl;
    }
    return 0;
}