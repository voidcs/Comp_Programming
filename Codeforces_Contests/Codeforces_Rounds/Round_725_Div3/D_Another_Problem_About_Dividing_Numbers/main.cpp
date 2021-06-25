#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int t;
    scanf("%d", &t);
    vector<ll> vis(50000), primes;
    for(ll i = 2; i*i <= 50000; i++){
        if(!vis[i]){
            for(ll j = i*i; j < 50000; j += i)
                vis[j] = 1;
        }
    }
    for(int i = 2; i < 50000; i++){
        if(!vis[i])
            primes.push_back(i);
    }
    while(t--){
        ll a, b, k;
        scanf("%lld%lld%lld", &a, &b, &k);
        int m = 0;
        if(a == b)
            m = 0;
        else if(__gcd(a, b) == a || __gcd(a, b) == b)
            m = 1;
        else
            m = 2;
        ll total = 0;
        for(ll x: primes){
            if(x*x > a)
                break;
            while(a % x == 0){
                total++, a /= x;
            }
        }
        if(a > 1)
            total++;
        for(ll x: primes){
            if(x*x > b)
                break;
            while(b % x == 0)
                total++, b /= x;
        }
        if(b > 1)
            total++;
        if(m <= k && k <= total && k == 1 && m == 1)
            printf("YES\n");
        else if(m <= k && k <= total && k != 1)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0; 
} 
