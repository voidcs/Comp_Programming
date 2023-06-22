#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];
    vector<int> dp(n, 2e9);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        if(i+1 < n)
            dp[i+1] = min(dp[i+1], dp[i] + abs(v[i] - v[i+1]));
        if(i+2 < n)
            dp[i+2] = min(dp[i+2], dp[i] + abs(v[i] - v[i+2]));
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
