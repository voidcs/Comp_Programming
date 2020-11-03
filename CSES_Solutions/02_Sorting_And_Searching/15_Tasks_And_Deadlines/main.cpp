#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin>>n;
    array<ll, 2> a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i][0]>>a[i][1];
    
    sort(a, a + n);
    //Simply complete shorter duration tasks first
    ll time = 0, ans = 0;
    for(int i = 0; i < n; i++){
        time += a[i][0];
        ans += (a[i][1] - time);
    }
    
    cout<<ans<<endl;
    return 0;
}