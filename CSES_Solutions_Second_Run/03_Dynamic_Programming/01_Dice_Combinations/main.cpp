#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = max(0, i-6); j < i; j++){
            dp[i] += dp[j];
            dp[i] %= mod;
        }
    }
    cout<<dp[n];
    
    return 0;
}