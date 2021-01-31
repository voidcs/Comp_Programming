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
    vector<ll> dp(n+1, 0), best;
    for(int i = 0; i < n; i++){
        ll index = lower_bound(best.begin(), best.end(), a[i]) - best.begin();
        if(index == best.size()){
            dp[i] = best.size();
            best.push_back(a[i]);
        }
        else{
            dp[i] = index;
            best[index] = a[i];
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, dp[i]+1);
    cout<<ans<<endl;
    
    return 0;
}