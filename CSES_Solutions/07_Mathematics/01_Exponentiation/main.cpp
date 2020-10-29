#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll expo_pow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b%2){
            b--;
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b/= 2;
    }
    return ans % mod;
}

int main(){
    ll t;
    scanf("%lld", &t);
    while(t--){
        ll a, b;
        scanf("%lld%lld", &a, &b);
        printf("%lld\n", expo_pow(a, b));
    }
    return 0;
}