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
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i >= a[j]){
                dp[i] += dp[i-a[j]];
                dp[i] %= mod;
            }
        }
    }
    cout<<dp[x]<<endl;
    
    return 0;
}