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
    sort(a.begin(), a.end());
    for(int i = 0; i < m; i++){
        cout<<lower_bound(a.begin(), a.end(), b[i]+1) - a.begin()<<" ";
    }
    return 0;
}
