#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    string a, b;
    cin>>a>>b;
    ll n = a.length(), m = b.length();
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, INF));
    for(int i = 0; i <= n; i++)
        dp[i][0] = i;
    for(int i = 0; i <= m; i++)
        dp[0][i] = i;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = min({dp[i][j], dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]+1});
            if(a[i-1] == b[j-1])
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            
        }
    }
    cout<<dp[n][m]<<endl;
    
    return 0;
}