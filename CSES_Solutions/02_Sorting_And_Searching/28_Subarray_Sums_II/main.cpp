#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n, x;
    cin>>n>>x;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    map<ll, ll> m;
    ll sum = 0, ans = 0;
    m[0]++;
    
    for(int i = 0; i < n; i++){
        sum += a[i];
        ans += m[sum-x];
        m[sum]++;
    }
    cout<<ans<<endl;
    return 0;
}