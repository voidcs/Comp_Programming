#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/contest/894/problem/A

int main(){
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    ll n = s.length();
    array<int, 3> dp = {0, 0, 0};
    for(int i = 0; i < n; i++){
        if(s[i] == 'Q'){
            dp[2] += dp[1];
            dp[0]++;
        }
        else if(s[i] == 'A'){
            dp[1] += dp[0];
        }
    }
    cout<<dp[2];
    return 0;
}