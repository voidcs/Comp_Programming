#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    ll ans = 0;
    ll cnt = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
        if(a[i])
            cnt++;
        else
            cnt2++;
    }
    ans = max(cnt, cnt2);
    vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
    dp[0][0] = dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
			//If the next number will make the segment end in a one,
			//There can be a one and a zero before it
            dp[i+1][1] = max(dp[i+1][1], dp[i][1]+1);
            dp[i+1][1] = max(dp[i+1][1], dp[i][0]+1);
        }
        else{
			//If the next number will make the segment end in a 0
			//There can only be a zero before it
            dp[i+1][0] = max(dp[i+1][0], dp[i][0]+1);
        }
		//Update the values by choosing not to use this element
        dp[i+1][1] = max(dp[i+1][1], dp[i][1]);
        dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
    }
    cout<<max(dp[n][0], dp[n][1])<<endl;
    return 0;
}