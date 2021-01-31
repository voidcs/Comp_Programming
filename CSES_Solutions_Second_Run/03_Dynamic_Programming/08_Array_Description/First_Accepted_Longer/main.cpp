#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, m;
    cin>>n>>m;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(m+1, 0));
    
    //Set base cases, if the first element is 0, then we can choose any value
    //And say that there is one way for each value
    //If a[0] is already set, we can only set dp[0][a[0]] to 1
    for(int i = 1; i <= m; i++){
        if(a[0] == 0)
            dp[0][i] = 1;
        else{
            if(i == a[0])
                dp[0][i] = 1;
        }
    }
    
    for(int i = 1; i < n; i++){
        if(a[i] != 0){
            //If the current and last indexes were already set and the difference
            //Is greater than zero, there are no more valid ways, set all to 0
            if(a[i-1] != 0 && abs(a[i]-a[i-1]) > 1){
                for(int j = 1; j <= m; j++)
                    dp[i][j] = 0;
            }
            //Take from previous ways with abs value less than or equal to 1
            else{
                if(a[i]-1 >= 1)
                    dp[i][a[i]] += dp[i-1][a[i]-1];
                if(a[i]+1 <= m)
                    dp[i][a[i]] += dp[i-1][a[i]+1];
                dp[i][a[i]] += dp[i-1][a[i]];
            }
        }
        else{
            //For each assumed value to be set, take from previous ways with
            //abs value less than or equal to 1
            for(int j = 1; j <= m; j++){
                if(j-1 >= 1)
                    dp[i][j] += dp[i-1][j-1];
                if(j+1 <= m)
                    dp[i][j] += dp[i-1][j+1];
                dp[i][j] += dp[i-1][j];
            }
        }
        for(int j = 1; j <= m; j++)
            dp[i][j] %= mod;
    }
    
    ll ans = 0;
    for(int i = 1; i <= m; i++)
        ans += dp[n-1][i];
    ans %= mod;
    cout<<ans<<endl;
    
    return 0;
}