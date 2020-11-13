#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;

int main(){
    ll n;
    cin>>n;
    vector<ll> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i - j < 0)
                break;
            dp[i] += dp[i-j] % mod;
        }
    }
    cout<<dp[n]%mod<<endl;
    return 0;
}