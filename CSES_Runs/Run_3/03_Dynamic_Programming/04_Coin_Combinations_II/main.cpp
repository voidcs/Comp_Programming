
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    ll n, x;
    cin>>n>>x;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    vector<ll> dp(x+1);
    dp[0] = 1;
    for(int j = 0; j < n; j++){
        for(int i = 0; i < x; i++){
            if(i + v[j] <= x){
                dp[i+v[j]] += dp[i];
                dp[i+v[j]] %= mod;
            }
        }
    }
    cout<<dp[x]<<endl;
}