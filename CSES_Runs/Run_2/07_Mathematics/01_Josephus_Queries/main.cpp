#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        function<ll(ll, ll)> solve = [&](ll n, ll k){
            if(k <= (n+1)/2){
                if(2*k > n)
                    return 1LL;
                else
                    return 2*k;  
            }
            ll x = solve(n/2, k - (n+1)/2);
            if(n%2)
                return 2*x+1;
            return 2*x-1;
        };
        
        cout<<solve(n, k)<<endl;
    }
    return 0;
}