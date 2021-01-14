#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/gym/302977/problem/B

int main(){
    ll n, k;
    cin>>n>>k;
    string str;
    cin>>str;
    char a[k];
    for(int i = 0; i < k; i++)
        cin>>a[i];
    map<char, int> m;
    for(int i = 0; i < k; i++)
        m[a[i]]++;
    
    //dp[i] represents how many strings we can make ending at this index
    vector<int> dp(n+1, 0);
    for(int i = 0; i < n; i++){
        if(m.count(str[i]))
            dp[i+1] = dp[i]+1;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        ans += dp[i];
    for(int i = 1; i <= n; i++)
        cout<<dp[i]<<" ";
    cout<<endl;
    cout<<ans<<endl;
    
    
    return 0; 
}
