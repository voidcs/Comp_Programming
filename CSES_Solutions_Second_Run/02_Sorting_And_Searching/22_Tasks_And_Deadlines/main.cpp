#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ll n;
    cin>>n;
    array<ll, 2> a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i][0]>>a[i][1];
    sort(a, a + n);
    ll ans = 0, t = 0;
    for(int i = 0; i < n; i++){
        t += a[i][0];
        ans += a[i][1] - t;
    }
    cout<<ans<<endl;
    
    return 0;
}