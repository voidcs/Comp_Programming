#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    ll n, k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    sort(v.begin(), v.end());
    ll l = 0, r = 1e9;
    ll ans = -1;
    auto valid = [&](ll r){
        ll birds = 0;
        for(int i = 0; i < n; i++){
            int j = i;
            while(j < n && v[j] - v[i] <= 2 * r){
                j++;
            }
            birds++;
            i = j - 1;
        }
        return birds <= k;
    };
    while(l <= r){
        ll m = (l + r) / 2;
        if(valid(m)){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
} 
