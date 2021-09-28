#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    vector<ll> dp(n+1, INF);
    dp[n] = 0;
    for(int i = n; i >= 1; i--){
        ll x = i;
        while(x){
            dp[i-(x%10)] = min(dp[i-(x%10)], dp[i]+1);
            x /= 10;
        }
    }
    cout<<dp[0]<<endl;
    
    return 0;
}