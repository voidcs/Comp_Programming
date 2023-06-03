#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, t, k;
    cin>>n>>t>>k;
    ll l = 1, r = n;
    ll ans = -1;
    while(l <= r){
        ll m = (l + r) / 2;
        cout<<"? 1 "<<m<<"\n";
        ll sum = 0;
        cin>>sum;
        if(m - sum >= k){
            r = m - 1;
            ans = m;
        }
        else{
            l = m + 1;
        }
    }
    cout<<"! "<<ans<<"\n";
} 
