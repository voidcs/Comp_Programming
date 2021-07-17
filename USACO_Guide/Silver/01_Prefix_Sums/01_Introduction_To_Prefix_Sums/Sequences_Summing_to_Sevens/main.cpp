#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    ll n;
    cin>>n;
    vector<ll> v(n);
    map<ll, ll> m;
    for(int i = 0; i < n; i++)
        cin>>v[i];
    ll sum = 0, ans = 0;
    m[0] = -1;
    for(int i = 0; i < n; i++){
        sum = (sum + v[i]) % 7;
        if(!m.count(sum)){
            m[sum] = i;
        }
        else{
            ans = max(ans, i - m[sum]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
