#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum += a[i];
    }
    sort(a, a + n);
    vector<ll> dp(sum+1, 0);
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = sum; j >= 0; j--){
            if(j >= a[i])
                dp[j] |= (dp[j-a[i]] == 1);
        }
    }
    vector<ll> ans;
    for(int i = 1; i <= sum; i++){
        if(dp[i])
            ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto x: ans)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}