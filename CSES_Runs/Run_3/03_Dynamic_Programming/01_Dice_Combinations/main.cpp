#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    ll n;
    cin>>n;
    vector<ll> dp(n+1);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int x = 1; x <= 6; x++){
            if(i+x <= n){
                dp[i+x] += dp[i];
                dp[i+x] %= mod;
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}