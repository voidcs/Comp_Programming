#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ll n, t;
    cin>>n>>t;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    function<bool(ll)> valid = [&](ll mid){
        ll sum = 0;
        for(int i = 0; i < n; i++){
            sum += mid/a[i];
            if(sum >= t)
                return true;
        }
        return sum >= t;
    };
    ll ans = 0;
    ll l = 0, r = INF;
    while(l <= r){
        ll mid = (l+r)/2;
        if(valid(mid)){
            r = mid-1;
            ans = mid;
        }
        else
            l = mid+1;
    }
    cout<<ans<<endl;
    
    return 0;
}