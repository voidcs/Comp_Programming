#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://www.spoj.com/problems/NHAY/
//REFERENCE
//https://www.youtube.com/watch?v=CcGcUfLDeH4&list=PL2q4fbVm1Ik6ThrYKCzgEpmaS_XWDGHjx&index=8

int main(){
    //freopen("input.txt", "r", stdin);
    int m;
    while(cin>>m){
        string needle, haystack;
        cin>>needle>>haystack;
        int n = haystack.length();
        vector<ll> dp(n);
        vector<ll> inv(n);
        
        auto expo_pow = [&](ll a, ll n){
            ll ans = 1;
            while(n){
                if(n%2)
                    ans = (ans * a) % mod;
                a = (a * a) % mod;
                n /= 2;
            }
            return ans;
        };
        
        auto init = [&](string s){
            ll p = 31, power = 1;
            inv[0] = 1;
            dp[0] = s[0] - 'a' + 1;
            for(int i = 1; i < s.length(); i++){
                power = (power * p) % mod;
                inv[i] = expo_pow(power, mod-2);
                dp[i] = (dp[i-1] + (s[i] - 'a' + 1) * power) % mod;
            }
        };
        
        auto getHash = [&](string s){
            ll res = 0;
            ll p = 31, power = 1;
            for(char c: s){
                res = (res + (c - 'a' + 1) * power) % mod;
                power = (power * p) % mod;
            }
            return res;
        };
        
        auto substringHash = [&](int l, int r){
            ll res = dp[r];
            if(l)
                res = (res - dp[l-1] + mod) % mod;
            res = (res * inv[l]) % mod;
            return res;
        };
        
        init(haystack);
        ll needleHash = getHash(needle);
        vector<int> ans;
        for(int i = 0; i < n-m+1; i++){
            if(substringHash(i, i + m-1) == needleHash)
                ans.push_back(i);
        }
        for(int x: ans)
            cout<<x<<endl;
    }
    return 0; 
} 