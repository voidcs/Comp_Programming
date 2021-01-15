#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin>>n;
    ll a[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum += a[i];
    }
    
    vector<vector<ll>> dp(n, vector<ll>(n));
    for(int i = n-1; ~i; i--){
        for(int j = i; j < n; j++){
            if(i == j){
                dp[i][j] = a[i];
            }
            else{
                dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
            }
        }
    }
    cout<<(sum+dp[0][n-1])/2<<endl;
    
    return 0;
}