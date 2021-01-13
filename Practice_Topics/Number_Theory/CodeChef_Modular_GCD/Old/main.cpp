#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
//PROBLEM LINK
//https://www.codechef.com/problems/GCDMOD
//REFERENCE VIDEO
//https://www.youtube.com/watch?v=rXnS4nf0T0M&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=19

ll pow(ll a, ll n, ll i){
    ll res = 1;
    while(n){
        if(n%2){
            res = ((res%i) * (a%i)) % i;
        }
        a = ((a%i) * (a%i)) % i;
        n /= 2;
    }
    return res;
}

ll getAns(ll a, ll b, ll n){
    
    if(a == b){
        return (pow(a, n, mod) + pow(b, n, mod)) % mod;
    }
    
    ll ans = 1;
    ll num = a-b;
    for(ll i = 1; i*i <= num; i++){
        ll r;
        if(num % i == 0){
            r = (pow(a, n, i) + pow(b, n, i)) % i;
            if(r == 0){
                ans = max(ans, (ll)i);
            } 
            
            r = (pow(a, n, num/i) + pow(b, n, num/i)) % (num/i);
            if(r == 0){
                ans = max(ans, num/i);
            } 
        }
    }
    return ans % mod;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b, n;
        cin>>a>>b>>n;
        cout<<getAns(a, b, n)<<endl;
    }
    return 0;
}
