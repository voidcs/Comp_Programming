#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll> a(n), b(m);
    for(ll &x: a)
        cin>>x;
    for(ll &x: b)
        cin>>x;
    ll l = 0, r = 1e18;
    ll ans = -1;
    auto valid = [&](ll r){
        int j = 0;
        for(int i = 0; i < n; i++){
            while(j < m && b[j] + r < a[i]){
                j++;
            }
            if(j == m)
                return false;
            if(a[i] < b[j] - r){
                return false;
            }
        }
        return true;
    };
    while(l <= r){
        ll mid = (l + r) / 2;
        if(valid(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout<<ans<<"\n";
} 
