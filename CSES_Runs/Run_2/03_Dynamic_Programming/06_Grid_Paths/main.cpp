#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    vector<vector<char>> g(n, vector<char>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>g[i][j];
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    dp[n-1][n-1] ^= (g[n-1][n-1] == '.');
    
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(g[i][j] == '*')
                continue;
            if(i + 1 < n){
                dp[i][j] += dp[i+1][j];
            }
            if(j + 1 < n)
                dp[i][j] += dp[i][j+1];
            dp[i][j] %= mod;
        }
    }
    cout<<dp[0][0]<<endl;
    
    return 0;
}