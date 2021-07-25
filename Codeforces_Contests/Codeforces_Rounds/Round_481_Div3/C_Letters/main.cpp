#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll> dorms(n+1), letters(m);
    for(int i = 1; i <= n; i++){
        cin>>dorms[i];
        dorms[i] += dorms[i-1];
    }
    for(ll &x: letters)
        cin>>x;
    for(ll x: letters){
        ll j = lower_bound(dorms.begin(), dorms.end(), x) - dorms.begin();
        j--;
        x -= dorms[j];
        cout<<j+1<<" "<<x<<endl;
    }
    return 0;
}
