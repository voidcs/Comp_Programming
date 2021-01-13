#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://www.codechef.com/problems/GCDMOD

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b, n;
        cin>>a>>b>>n;
        ll diff = a-b;
        set<ll, greater<ll>> s;
        for(ll i = 1; i*i <= diff; i++){
            if(diff % i == 0){
                s.insert(i);
                s.insert(diff/i);
            }
        }
        
        function<ll(ll, ll, ll)> expo_pow = [&](ll base, ll pow, ll m){
            ll res = 1;
            while(pow){
                if(pow%2){
                    pow--;
                    res = ((res%m)*(base%m)) % m;
                }
                base = ((base%m)*(base%m)) % m;
                pow /= 2;
            }
            return res;
        };
        ll ans = 1;
        if(a == b){
            cout<<(expo_pow(a, n, mod) + expo_pow(b, n, mod)) % mod<<endl;
            continue;
        }
        for(auto x: s){
            ll sum = (expo_pow(a, n, x) + expo_pow(b, n, x))%x;
            if(sum % x == 0){
                ans = max(ans, x);
                break;
            }
        }
        cout<<ans%mod<<endl;
    }
    
    return 0;
}