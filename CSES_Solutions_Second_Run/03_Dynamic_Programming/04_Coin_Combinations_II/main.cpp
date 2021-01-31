#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, x;
    cin>>n>>x;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(j >= a[i]){
                dp[j] += dp[j-a[i]];
                dp[j] %= mod;
            }
        }
    }
    cout<<dp[x]<<endl;
    
    return 0;
}