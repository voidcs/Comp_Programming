#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

//PROBLEM LINK
//https://www.spoj.com/problems/MARBLES/
//REFERENCE
//https://cp-algorithms.com/combinatorics/binomial-coefficients.html

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        auto c = [&](ll n, ll k){
            long double ans = 1;
            for(int i = 1; i <= k; i++){
                ans = ans * (n-k+i)/i;
            }
            return (ll)(ans + 0.01);
        };
        cout<<c(n-1, k-1)<<endl;
    }
    return 0;
}