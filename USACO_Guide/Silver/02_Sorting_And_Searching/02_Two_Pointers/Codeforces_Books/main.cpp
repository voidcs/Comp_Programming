#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, t;
    cin>>n>>t;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    ll l = 0, r = 0, sum = 0, cnt = 0, ans = 0;
    while(r < n){
        sum += v[r++];
        cnt++;
        while(sum > t){
            sum -= v[l++];
            cnt--;
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;
    return 0;
}
