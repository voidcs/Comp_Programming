#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    map<ll, ll> m;
    for(ll &x: v){
        cin>>x;
        m[x]++;
    }
    int maxN = 1e5+5;
    vector<ll> dp(maxN);
    for(int i = 0; i < maxN; i++){
        dp[i] = max(dp[i], i * m[i]);
        if(i-2 >= 0)
            dp[i] = max(dp[i], dp[i-2] + (i * m[i]));
        if(i-3 >= 0)
            dp[i] = max(dp[i], dp[i-3] + (i * m[i]));
    }
    ll ans = 0;
    for(int i = 0; i < maxN; i++)
        ans = max(ans, dp[i]);
    cout<<ans<<endl;
    return 0;
}
