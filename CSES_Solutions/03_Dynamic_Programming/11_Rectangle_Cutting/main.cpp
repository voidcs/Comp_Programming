#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, INF));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == j){
                dp[i][j] = 0;
                continue;
            }
            for(int k = 1; k < i; k++)
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]+1);
            for(int k = 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k]+1);
        }
    }
    cout<<dp[n][m]<<endl;
    
    return 0;
}