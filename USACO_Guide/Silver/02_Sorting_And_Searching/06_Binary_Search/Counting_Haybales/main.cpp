#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    ll n, q;
    cin>>n>>q;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    sort(v.begin(), v.end());
    while(q--){
        ll l, r;
        cin>>l>>r;
        r = upper_bound(v.begin(), v.end(), r) - v.begin();
        l = lower_bound(v.begin(), v.end(), l) - v.begin();
        cout<<r - l<<"\n";
    }
}
