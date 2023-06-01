#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    ll n, m, c;
    cin>>n>>m>>c;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    sort(v.begin(), v.end());
    ll l = 0, r = 1e9;
    ll ans = -1;
    auto valid = [&](ll max_diff){
        ll buses = 0;
        for(int i = 0; i < n; i++){
            int j = i;
            while(j < n && v[j] - v[i] <= max_diff && j-i+1 <= c){
                j++;
            }
            i = j - 1;
            buses++;
        }
        return buses <= m;
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
} 
