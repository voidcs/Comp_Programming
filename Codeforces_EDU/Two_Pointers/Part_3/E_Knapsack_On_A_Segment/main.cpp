#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, s;
    cin>>n>>s;
    vector<ll> w(n), c(n);
    for(ll &x: w)
        cin>>x;
    for(ll &x: c)
        cin>>x;
    ll ans = 0, l = 0, sum = 0, weightUsed = 0;
    for(int r = 0; r < n; r++){
        sum += c[r];
        weightUsed += w[r];
        while(weightUsed > s){
            weightUsed -= w[l];
            sum -= c[l];
            l++;
        }
        ans = max(ans, sum);
    }
    cout<<ans<<endl;
    return 0;
}