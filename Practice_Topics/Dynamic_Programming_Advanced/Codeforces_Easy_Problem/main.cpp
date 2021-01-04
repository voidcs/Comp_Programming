#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

//PROBLEM LINK
//https://codeforces.com/contest/1096/problem/D

int main(){
    int n;
    string str;
    cin>>n>>str;
    int a[n+1];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    vector<vector<ll>> dp(n+1, vector<ll>(4, INF));
    string hard = "hard";
    for(int i = 0; i < 4; i++)
        dp[0][i] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            if(str[i] != hard[j])
                dp[i+1][j] = dp[i][j];
            else
                dp[i+1][j] = dp[i][j] + a[i];
        }
        for(int j = 1; j < 4; j++)
            dp[i+1][j] = min(dp[i+1][j], dp[i+1][j-1]);
    }
    ll ans = INF;
    for(int i = 0; i < 4; i++)
        ans = min(ans, dp[n][i]);
    cout<<ans<<endl;
    
    return 0;
}