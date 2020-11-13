#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;

int main(){
    ll n;
    cin>>n;
    char a[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>a[i][j];
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[n-1][n-1] = (a[n-1][n-1] != '*');
    
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(a[i][j] == '*')
                continue;
            if(i+1 < n)
                dp[i][j] = (dp[i][j] + dp[i+1][j]) % mod;
            if(j+1 < n)
                dp[i][j] = (dp[i][j] + dp[i][j+1]) % mod;
        }
    }
    cout<<dp[0][0];
    
    return 0;
}