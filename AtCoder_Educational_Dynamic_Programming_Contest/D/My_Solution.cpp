#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e10;

int main(){
    ll n, w;
    scanf("%lld%lld", &n, &w);
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++){
        int x, y;
        cin>>x>>y;
        a[i] = {x, y};
    }
    
    ll dp[n][w+1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= w; j++){
            dp[i][j] = 0;
        }
    }
    
    for(int i = 0; i <= w; i++){
        if(i >= a[0].first){
            dp[0][i] = a[0].second;
        }
    }
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= w; j++){
            if(j < a[i].first){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-a[i].first] + a[i].second, dp[i-1][j]);
            }
        }
    }
    
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j <= w; j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
        
    cout<<dp[n-1][w];
    
    
    return 0;
}