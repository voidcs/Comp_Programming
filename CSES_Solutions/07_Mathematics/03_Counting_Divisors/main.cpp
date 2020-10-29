#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const int maxN = 1e6 + 5;
int lpf[maxN];
vector<int> primes;
 
void sieve(){
    for(int i = 2; i <= maxN; i++){
        if(!lpf[i]){
            lpf[i] = i;
            primes.push_back(i);
        }
        
        for(int j = 0; j < primes.size() && primes[j] <= lpf[i] && primes[j]*i < maxN; j++)
            lpf[i*primes[j]] = primes[j];
    }
}
 
int main(){
    sieve();
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        map<ll, ll> m;
        while(n > 1){
            m[lpf[n]]++;
            n /= lpf[n];
        }
        
//        for(auto x: m)
//            cout<<x.first<<"   "<<x.second<<endl;
        ll ans = 1;
        for(auto x: m)
            ans *= (x.second + 1);
        
        cout<<ans<<endl;
    }
    return 0;
}