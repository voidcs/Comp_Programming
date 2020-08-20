#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e10;

int main(){
    ll n;
    scanf("%lld", &n);
    
    ll a[n];
    for(int i = 0; i < n; i++)
        scanf("%lld", a + i);
    
    vector<ll> dp(n, INF);
    
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j <= i + 2; j++){
            if(j < n){
                dp[j] = min(dp[j], dp[i] + abs(a[i] - a[j]));
            }
        }
    }
    
    cout<<dp[n-1];
    
    return 0;
}