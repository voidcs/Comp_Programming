#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

int main(){
    ll n, m;
    cin>>n>>m;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        a[i]--;
    }
    
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    
    for(int i = 0; i < n; i++){
        if(i){
            for(int j = 0; j < m; j++){
                dp[i][j] = dp[i-1][j];
                if(j)
                    dp[i][j] += dp[i-1][j-1];
                if(j < m-1)
                    dp[i][j] += dp[i-1][j+1];
                dp[i][j] %= mod;
            }
        }
        else{
            for(int j = 0; j < m; j++)
                dp[0][j] = 1;
        }
        
        if(~a[i]){
            for(int j = 0; j < m; j++){
                if(j != a[i])
                    dp[i][j] = 0;
            }
        }
    }
    
    ll ans = 0;
    for(int i = 0; i < m; i++)
        ans += dp[n-1][i];
    
    cout<<ans%mod<<endl;
    return 0;
}