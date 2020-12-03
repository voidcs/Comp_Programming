#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    ll ans = 0;
    ll low = a[0], high = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > high)
            ans++;
        else if(a[i] < low)
            ans++;
        low = min(low, a[i]);
        high = max(high, a[i]);
    }
    cout<<ans<<endl;
    
    return 0;
}