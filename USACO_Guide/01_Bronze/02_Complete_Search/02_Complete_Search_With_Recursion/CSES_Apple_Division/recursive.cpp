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
    function<ll(int, ll, ll)> solve = [&](int i, ll a, ll b){
        if(i == n)
            return abs(a - b);
        return min(solve(i + 1, a, b + v[i]), solve(i + 1, a + v[i], b));
    };
    ll ans = solve(0, 0, 0);
    cout<<ans<<endl;
    
    return 0;
}