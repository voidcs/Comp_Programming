#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    ll ans = a[0], curr = a[0];
    for(int i = 1; i < n; i++){
        curr = max(curr + a[i], a[i]);
        ans = max(ans, curr);
    }
    cout<<ans<<endl;
    
    return 0;
}