#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, k;
    cin>>n>>k;
    ll sum = 0;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        ll a, b;
        cin>>a>>b;
        sum += a;
        v.push_back(a-b);
    }
    sort(v.rbegin(), v.rend());
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(sum <= k)
            break;
        sum -= v[i];
        ans++;
    }
    if(sum > k)
        cout<<"-1\n";
    else
        cout<<ans<<endl;
    return 0;
}
