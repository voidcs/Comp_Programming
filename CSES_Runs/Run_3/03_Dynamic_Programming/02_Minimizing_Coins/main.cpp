#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    ll n, x;
    cin>>n>>x;
    vector<ll> dp(x+1, INF);
    dp[0] = 0;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    for(int i = 0; i < x; i++){
        for(int j = 0; j < n; j++){
            if(v[j] + i <= x){
                dp[i+v[j]] = min(dp[i+v[j]], dp[i]+1);
            }
        }
    }
    if(dp[x] == INF)
        cout<<"-1\n";
    else
        cout<<dp[x]<<endl;
    return 0;
}