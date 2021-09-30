#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    int x;
    cin>>x;
    vector<int> dp(x+1, 1e9);
    dp[x] = 0;
    for(int i = x; i > 0; i--){
        int n = i;
        while(n){
            int d = n%10;
            dp[i-d] = min(dp[i-d], dp[i]+1);
            n /= 10;
        }
    }
    cout<<dp[0]<<endl;
    return 0;
}