#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = INT_MAX;
const ll maxN = 2e5;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    vector<ll> dp(maxN+1, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = maxN; j >= 1; j--){
            if(j >= a[i])
                dp[j] = min(dp[j], dp[j-a[i]] + 1);
        }
    }
    
    vector<ll> ans;
    for(int i = 1; i <= maxN; i++){
        if(dp[i] != INF)
            ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto x: ans)
        cout<<x<<" ";
    
    return 0;
}