//https://codeforces.com/contest/702/problem/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll> cities(n), towers(m);
    for(ll &x: cities)
        cin>>x;
    for(ll &x: towers)
        cin>>x;
    ll ans = 0, l = 0, r = 1e10;
    auto valid = [&](ll x){
        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < m && towers[j] + x < cities[i])
                j++;
            if(j >= m)
                return false;
            if(abs(towers[j] - cities[i]) > x)
                return false;
        }
        return true;
    };
    while(l <= r){
        ll m = (l+r)/2;
        if(valid(m)){
            ans = m;
            r = m-1;
        }
        else
            l = m+1;
    }
    cout<<ans<<endl;
    return 0;
}
