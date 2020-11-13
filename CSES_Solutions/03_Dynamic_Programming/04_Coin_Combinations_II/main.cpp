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
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(j - a[i] >= 0){
                if(dp[j-a[i]])
                    dp[j] = (dp[j] + dp[j-a[i]]) % mod;
            }
        }
    }
    cout<<dp[x];
    
    return 0;
}