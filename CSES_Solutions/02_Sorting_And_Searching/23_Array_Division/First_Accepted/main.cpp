#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n, k;
    cin>>n>>k;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    auto valid = [&](ll x, ll k){
        ll count = 1, sum = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > x)
                return false;
            if(a[i] + sum > x){
                count++;
                sum = a[i];
            }
            else
                sum += a[i]; 
        }
        return count <= k;
    };
    
    ll l = 0, r = INF;
    ll ans = INF;
    while(l <= r){
        ll mid = (l+r)/2;
        if(valid(mid, k)){
            r = mid-1;
            ans = mid;
        }
        else
            l = mid+1;
    }
    
    cout<<ans<<endl;
    
    return 0;
}