#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/474/D

ll mod = 1e9 + 7;
ll k;
ll pre[100001];
ll dp [100001];

ll getAns(ll n){
    if(n == 0)
        return 1;
    
    if(dp[n] != -1)
        return dp[n];
    
    ll ans = 0;
    //White flower
    if(n >= k){
        ans += getAns(n-k);
        ans %= mod;
    }
    
    //Red flower
    ans += getAns(n-1);
    ans %= mod;
    
    return dp[n] = ans;
}

void init(){
    for(int i = 1; i <= 100000; i++)
        dp[i] = -1;
    
    for(int i = 1; i <= 100000; i++)
        pre[i] = pre[i-1] + getAns(i);
}

int main(){
    ll t;
    scanf("%lld%lld", &t, &k);
    init();
    
    while(t--){
        ll a, b;
        scanf("%lld%lld", &a, &b);
        
        ll sum = (pre[b] - pre[a-1] + mod) % mod;
        
        printf("%lld\n", sum);
    }
    
    return 0;
}