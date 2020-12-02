#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n, k;
    cin>>n>>k;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    ll ans = 0;
    ll m = a[k-1];
    for(int i = 0; i < n; i++){
        if(a[i] >= m && a[i] > 0)
            ans++;
    }
    cout<<ans<<endl;
    
    return 0;
}