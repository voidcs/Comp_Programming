#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const ll INF = 1e18;

int main(){
    int n;
    cin>>n;
    vector<ll> dp(n+1, INF);
    dp[n] = 0;
    for(int i = n; i; i--){
        ll temp = i;
        while(temp){
            ll x = temp % 10;
            dp[i-x] = min(dp[i-x], dp[i]+1);
            temp /= 10;
        }
    }
    cout<<dp[0];
    
    return 0;
}