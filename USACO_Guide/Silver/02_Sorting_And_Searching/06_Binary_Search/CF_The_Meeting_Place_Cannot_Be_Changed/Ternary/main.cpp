#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
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
    auto f = [&](long double m){
        long double res = 0;
        for(int i = 0; i < n; i++){
            res = max(res, abs(pos[i] - m) / v[i]);
        }
        return res;
    };
    while(r - l > eps){
        long double m1 = l + (r-l) / 3;
        long double m2 = r - (r-l)/3;
        long double f1 = f(m1);
        long double f2 = f(m2);
        if(f1 < f2){
            ans = f1;
            r = m2;
        }
        else{
            l = m1;
        }
    }
    cout<<fixed<<setprecision(8)<<ans<<"\n";
    return 0;
} 