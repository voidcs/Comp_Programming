#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    map<ll, ll> m;
    ll sum = 0, ans = 0;
    m[0]++;
    
    for(int i = 0; i < n; i++){
        sum = (sum+a[i]%n+n) % n;
        ans += m[sum];
        m[sum]++;
    }
    cout<<ans<<endl;
    
    return 0;
}