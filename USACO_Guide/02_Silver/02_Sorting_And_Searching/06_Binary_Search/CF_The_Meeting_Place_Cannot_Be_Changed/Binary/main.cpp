#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll> pos(n), v(n);
    for(ll &x: pos)
        cin>>x;
    for(ll &x: v)
        cin>>x;
    long double eps = 1e-7;
    long double l = 0, r = 1e10;
    long double ans = INF;
    auto valid = [&](long double m){
        long double left = -INF, right = INF;
        for(int i = 0; i < n; i++){
            left = max(left, pos[i] - (m * v[i]));
            right = min(right, pos[i] + (m * v[i]));
        }
        return right - left >= eps;
    };
    while(r - l > eps){
        long double m = (l+r)/2;
        if(valid(m)){
            ans = m;
            r = m;
        }
        else{
            l = m;
        }
    }
    cout<<fixed<<setprecision(8)<<ans<<"\n";
    return 0;
} 
