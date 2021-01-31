#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, INF));
    for(int i = 0; i <= min(n, m); i++){
        dp[i][i] = 0;
    }
    
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            //Cut along the y axis, assume the new lengths are k and j-k
            for(int k = 1; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            }
            //Cut along the x axis, assume the new lengths are k and i-k
            for(int k = 1; k < i; k++){
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            }
        }
    }
    
    cout<<dp[n][m]<<endl;
    
    return 0;
}