#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main() {
    ll n;
    cin>>n;
    ll sum = (n*(n+1))/2;
    if(sum%2) {
        cout<<"0\n";
        return 0;
    }
    
    ll target = sum/2;
    vector<vector<ll>> dp(target+1, vector<ll>(n+1, 0));
    for(int i = 0; i <= n; i++){
        dp[0][i] = 1;
    }
    //Do not have to divide final answer by two if dp[0][0] is set to 0
    //dp[0][0] = 0;
    for(int i = 1; i <= target; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] += dp[i][j-1];
            if(i >= j)
                dp[i][j] += dp[i-j][j-1];
            dp[i][j] %= mod;
        }
    }
    function<ll(ll, ll)> expo_pow = [&](ll base, ll pow){
        ll res = 1;
        while(pow){
            if(pow%2){
                res = (res*base)%mod;
            }
            base = (base*base) % mod;
            pow /= 2;
        }
        return res;
    };
    ll inv = expo_pow(2, mod-2);
    cout<<(dp[target][n]*inv)%mod<<endl;
    
    return 0;
}