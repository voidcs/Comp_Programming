#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e3 + 5;

//PROBLEM LINK
//https://atcoder.jp/contests/dp/tasks/dp_e

int main(){
    ll n, w;
    scanf("%lld%lld", &n, &w);
    vector<ll> weight(n), value(n);
    for(int i = 0; i < n; i++)
        scanf("%lld%lld", &weight[i], &value[i]);
    
    ll sum = 0;
    for(int i = 0; i < n; i++)
        sum += value[i];
    
    vector<ll> dp(sum + 1, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = sum - value[i]; j >= 0; j--){
            dp[j + value[i]] = min(dp[j + value[i]], dp[j] + weight[i]);
        }
    }
    
    ll ans = 0;
    for(int i = 0; i <= sum; i++){
        if(dp[i] <= w){
            ans = max(ans, (ll)i);
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}