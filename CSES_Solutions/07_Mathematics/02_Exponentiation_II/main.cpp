#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll expo_pow(ll a, ll b, ll m){
    ll ans = 1;
    while(b){
        if(b%2){
            b--;
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return ans % m;
}

int main(){
    ll t;
    scanf("%lld", &t);
    while(t--){
        ll a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        printf("%lld\n", expo_pow(a, expo_pow(b, c, mod-1), mod));
    }
    
    return 0;
}