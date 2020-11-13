#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9 + 7;
const ll INF = 1e18;

int main(){
    ll n, x;
    cin>>n>>x;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    vector<ll> dp(x+1, INF);
    dp[0] = 0;
    sort(a, a + n);
    
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i >= a[j]){
                dp[i] = min(dp[i], dp[i-a[j]]+1);
            }
        }
    }
    if(dp[x] == INF)
        cout<<"-1\n";
    else
        cout<<dp[x];
    
    return 0;
}