#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

//PROBLEM LINK
//https://codeforces.com/gym/302977/problem/C

int main(){
    ll n;
    cin>>n;
    vector<vector<ll>> dp(n+1, vector<ll>(8, INF));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        ll cost;
        string str;
        cin>>cost>>str;
        int mask = 0;
        for(int j = 0; j < 3; j++){
            for(char c: str){
                if(c == 'A' + j)
                    mask |= 1<<j;
            }
        }
        for(int j = 0; j < 8; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            dp[i+1][j|mask] = min(dp[i+1][j|mask], dp[i][j] + cost);
        }
    }
    if(dp[n][7] == INF)
        cout<<"-1\n";
    else
        cout<<dp[n][7]<<endl;
    
    return 0;
}