#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 1e18;

int main(){
    ll n, x;
    cin>>n>>x;
    ll a[n], b[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    for(int i = 0; i < n; i++)
        cin>>b[i];
    
    vector<ll> dp(x+1, 0);
    for(int i = 0; i < n; i++){
        for(int j = x; j >= 0; j--){
            if(j >= a[i])
                dp[j] = max(dp[j], dp[j-a[i]] + b[i]);
        }
    }
    cout<<dp[x];
    return 0;
}