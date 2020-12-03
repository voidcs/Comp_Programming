#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll high = -1, low = 1e5;
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        high = max(high, a[i]);
        low = min(low, a[i]);
    }
    
    ll highIndex, lowIndex;
    for(int i = 0; i < n; i++){
        if(a[i] == low)
            lowIndex = i;
        if(a[n-1-i] == high)
            highIndex = n-1-i;
    }
    ll ans = 0;
    ans += (n - lowIndex - 1);
    ans += highIndex;
    if(highIndex > lowIndex)
        ans--;
    cout<<ans<<endl;
    
    return 0;
}