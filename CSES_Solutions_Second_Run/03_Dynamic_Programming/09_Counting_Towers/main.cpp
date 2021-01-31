#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll maxN = 1e6+5;
    vector<vector<ll>> dp(maxN, vector<ll>(3, 0));
    dp[1][1] = 1, dp[1][2] = 1;
    for(int i = 2; i < maxN; i++){
        //Placing a long block on top of two small blocks
        dp[i][1] += dp[i-1][2];
        //Placing a long block on top of a long block and also just
        //extending the long block below
        dp[i][1] += 2*dp[i-1][1];
        
        //Placing two small blocks on top of a long block
        dp[i][2] += dp[i-1][1];
        //Placing two small blocks on top of two small blocks
        //Extending both small blocks to one more level
        //Extending only the left block and putting a small block on right
        //Extending only the right block and putting a small block on left
        dp[i][2] += 4*dp[i-1][2];
        dp[i][1] %= mod, dp[i][2] %= mod;
    }
    
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<(dp[n][1]+dp[n][2])%mod<<endl;
    }
    
    return 0;
}