#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, k;
    cin>>n>>k;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    ll ans = 0;
    ll l = 0, r = 1e18;
    
    function<bool(ll)> valid = [&](ll mid){
        ll sum = 0, cnt = 1;
        for(int i = 0; i < n; i++){
            if(a[i] > mid)
                return false;
            if(sum + a[i] <= mid){
                sum += a[i];
            }
            else{
                sum = a[i], cnt++;
            }
        }
        return cnt <= k;
    };
    
    while(l <= r){
        ll mid = (l+r)/2;
        if(valid(mid)){
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid+1;
    }
    cout<<ans<<endl;
    
    return 0;
}