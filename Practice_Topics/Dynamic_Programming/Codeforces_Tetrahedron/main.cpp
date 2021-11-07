#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<array<int, 4>> dp(n+1, {0, 0, 0, 0});
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                if(j != k){
                    dp[i][j] = (dp[i][j] + dp[i-1][k]);
                    if(dp[i][j] >= mod)
                        dp[i][j] -= mod;
                }
            }
        }
    }
    cout<<dp[n][0]<<endl;
    return 0;
}
