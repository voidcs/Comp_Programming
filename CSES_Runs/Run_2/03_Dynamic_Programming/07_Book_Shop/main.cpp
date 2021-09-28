#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, x;
    cin>>n>>x;
    ll weight[n], cost[n];
    for(int i = 0; i < n; i++)
        cin>>cost[i];
    for(int i = 0; i < n; i++)
        cin>>weight[i];
    vector<ll> dp(x+1, 0);
    for(int i = 0; i < n; i++){
        for(int j = x; j >= 0; j--){
            if(j >= cost[i]){
                dp[j] = max(dp[j], dp[j-cost[i]] + weight[i]);
            }
        }
    }
    cout<<dp[x];
    
    return 0;
}