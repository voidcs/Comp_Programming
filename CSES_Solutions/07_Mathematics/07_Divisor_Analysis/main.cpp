#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    ll divisors = 1, sum = 1, product = 1;
    ll count = 1;
    while(n--){
        ll a, b;
        cin>>a>>b;
        
        function<ll(ll,ll, ll)> expo = [&](ll base, ll pow, ll mod){
            ll x = 1;
            while(pow){
                if(pow%2){
                    x = (x*base)%mod;
                }
                base = (base*base) % mod;
                pow /= 2;
            }
            return x % mod;
        };
        
        //For calculating sum use https://cp-algorithms.com/algebra/divisors.html#toc-tgt-1
        ll num = expo(a, b+1, mod) - 1;
        num = (num + mod) % mod;
        //Use b^(mod-2) to find mod inverse
        ll x = expo(a-1, mod-2, mod);
        sum = ((sum%mod) * (((num%mod)* (x%mod))%mod)) % mod;
        
        //For Divisors
        divisors = ((divisors%mod) * ((b+1)%mod)) % mod;
        
        //For product
		//https://www.geeksforgeeks.org/product-of-divisors-of-a-number-from-a-given-list-of-its-prime-factors/
        ll val = expo(a, (b*(b+1))/2, mod);
        product = expo(product, b+1, mod) * expo(val, count, mod);
        product %= mod;
        count = (count * (b+1)) % (mod-1);
    }
    cout<<divisors<<" "<<sum<<" "<<product<<endl;
    return 0; 
}
