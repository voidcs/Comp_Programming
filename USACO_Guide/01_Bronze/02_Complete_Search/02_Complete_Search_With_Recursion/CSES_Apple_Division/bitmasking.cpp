#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n;
    cin>>n;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    
    ll ans = INF;
    for(int i = 0; i < (1<<n); i++){
        ll a = 0, b = 0;
        for(int j = 0; j < n; j++){
            if(i & (1 << j))
                a += v[j];
            else
                b += v[j];
        }
        ans = min(ans, abs(a - b));
    }
    cout<<ans<<endl;
    
    return 0;
}