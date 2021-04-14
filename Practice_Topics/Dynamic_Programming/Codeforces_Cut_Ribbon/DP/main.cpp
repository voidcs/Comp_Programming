#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    int a[3];
    cin>>n;
    for(int i = 0; i < 3; i++)
        cin>>a[i];
    vector<int> dp(n+1);
    for(int i = 0; i < 3; i++){
        for(int j = 1; j <= n; j++){
            if(j - a[i] < 0)
                continue;
            if(dp[j-a[i]] || j-a[i] == 0)
                dp[j] = max(dp[j], dp[j-a[i]]+1);
        }
    }
    cout<<dp[n]<<endl;
    
    return 0;
}