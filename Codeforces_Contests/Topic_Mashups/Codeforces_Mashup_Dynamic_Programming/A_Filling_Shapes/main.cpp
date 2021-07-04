#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codeforces.com/gym/302977/problem/A

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, 0);
    dp[0] = 1, dp[1] = 0;
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-2]*2;
    cout<<dp[n];
    return 0;
}