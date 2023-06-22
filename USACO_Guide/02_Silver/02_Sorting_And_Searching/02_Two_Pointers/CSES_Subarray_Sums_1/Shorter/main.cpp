#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, x;
    cin>>n>>x;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    ll ans = 0;
    ll l = 0, r = 0, sum = 0;
    while(r < n){
        sum += v[r++];
        while(sum > x){
            sum -= v[l++];
        }
        if(sum == x)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
