#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://atcoder.jp/contests/dp/tasks/dp_c

const ll INF = 1e10;

int main(){
    ll n;
    scanf("%lld", &n);

    ll days = n;
    vector<ll> dp(3);
    while(days--){
        vector<ll> new_dp(3, 0);
        vector<ll> v(3);
        for(int i = 0; i < 3; i++)
            scanf("%lld", &v[i]);
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i != j){
                    new_dp[j] = max(new_dp[j], dp[i] + v[j]);
                }
            }
        }
        dp = new_dp;
    }
    
    printf("%lld", max({dp[0], dp[1], dp[2]}));
    
    return 0;
}