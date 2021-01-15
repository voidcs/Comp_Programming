#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n = 1e6+5;
    vector<vector<ll>> dp(n+1, vector<ll>(3, 0));
    dp[1][1] = dp[1][2] = 1;
    //dp[i][1] represents ways with last being two width 1 blocks
    //dp[i][2] represents ways with last block being a width 2 block
    for(int i = 1; i < n; i++){
        //Place stuff on top of a width 2 block
        ll op1 = (dp[i][1] + dp[i][2]) % mod;
        
        //Extend one of the blocks of width 1 
        //(Multiply by two because they're the same case)
        ll op2 = (2*dp[i][1]) % mod;
        
        //Extending both of the blocks of width 1
        ll op3 = dp[i][1] % mod;
        
        //Extend the width 2 block higher
        ll op4 = dp[i][2] % mod;
        dp[i+1][1] = (op1+op2+op3) % mod;
        dp[i+1][2] = (op1+op4) % mod;
    }
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<(dp[n][1]+dp[n][2]) % mod<<endl;
    }
    return 0; 
}