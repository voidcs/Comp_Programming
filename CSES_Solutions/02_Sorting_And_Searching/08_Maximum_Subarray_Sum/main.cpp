#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    ll ans = -INF, sum = -INF;
    for(int i = 0; i < n; i++){
        sum = max(a[i], sum + a[i]);
        ans = max(ans, sum);
    }
    cout<<ans<<endl;
    
    return 0;
}