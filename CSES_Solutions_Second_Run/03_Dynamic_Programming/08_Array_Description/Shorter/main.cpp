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
        //Take all previous ways with abs difference of <= 1
        for(int j = 1; j <= m; j++){
            if(a[i] == 0 || a[i] == j){
                if(j-1 >= 1)
                    dp[i][j] += dp[i-1][j-1];
                if(j+1 <= m)
                    dp[i][j] += dp[i-1][j+1];
                dp[i][j] += dp[i-1][j];
            }
            dp[i][j] %= mod;
        }
    }

    ll ans = 0;
    for(int i = 1; i <= m; i++)
        ans += dp[n-1][i];
    ans %= mod;
    cout<<ans<<endl;
    
    return 0;
}