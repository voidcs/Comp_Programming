#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n, k;
    cin>>n>>k;
    ll a[n], b[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < n; i++)
        cin>>b[i];
    vector<ll> pref(n+1, 0);
    ll have = 0;
    for(int i = 0; i < n; i++){
        if(b[i]){
            have += a[i];
            pref[i+1] = pref[i];
        }
        else{
            pref[i+1] = pref[i] + a[i];
        }
    }
    ll ans = 0;
    for(int i = 0; i+k-1 < n; i++){
        ans = max(ans, have + pref[i+k] - pref[i]);
    }
    cout<<ans<<endl;
    return 0; 
}