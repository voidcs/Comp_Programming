#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll &x: v)
            cin>>x;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll x = -1;
            if(i+1 < n)
                x = max(x, v[i+1]);
            if(i-1 >= 0)
                x = max(x, v[i-1]);
            if(x == -1 || x >= v[i])
                continue;
            ans += v[i] - x;
            v[i] = x;
        }
        for(int i = 0; i < n; i++){
            if(!i || i == n-1)
                ans += v[i];
            if(i)
                ans += abs(v[i] - v[i-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}