#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, a, b, p, q;
    cin>>n>>a>>b>>p>>q;
    if(a == b){
        cout<<(n/a) * (max(p, q))<<endl;
        return 0;
    }
    ll x = 0, y = 0;
    x = n/a;
    y = n/b;
    ll g = (a*b) / __gcd(a, b);
    x -= (n / g);
    y -= (n / g);
    ll z = n / g;
    ll ans = (x*p) + (y*q) + (z*max(p, q));
    cout<<ans<<endl;
    return 0;
}
