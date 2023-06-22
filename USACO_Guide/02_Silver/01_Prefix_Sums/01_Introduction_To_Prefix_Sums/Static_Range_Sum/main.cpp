#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll> v(n), p(n+1);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        sum += v[i];
        p[i+1] = sum;
    }
    while(m--){
        ll l, r;
        cin>>l>>r;
        l++;
        cout<<p[r] - p[l-1]<<endl;
    }
    return 0;
}
