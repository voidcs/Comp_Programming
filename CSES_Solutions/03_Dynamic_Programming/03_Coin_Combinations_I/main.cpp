#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;

int main(){
    ll n, x;
    cin>>n>>x;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    vector<int> dp(x+1, 0);
    
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i-a[j] >= 0){
                if(dp[i-a[j]]){
                    dp[i] = (dp[i] + dp[i-a[j]]) % mod;
                }
            }
        }
    }
    
    cout<<dp[x];
    return 0;
}