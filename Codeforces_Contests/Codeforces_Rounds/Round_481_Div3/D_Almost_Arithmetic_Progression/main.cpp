#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    if(n <= 2){
        cout<<"0\n";
        return 0;
    }
    vector<array<ll, 2>> candidates;
    for(ll a: {-1, 0, 1}){
        for(ll b: {-1, 0, 1}){
            ll first = v[0] + a;
            ll second = v[1] + b;
            candidates.push_back({first, second - first});
        }
    }
    ll ans = INF;
    for(auto x: candidates){
        ll curr = x[0];
        ll dx = x[1];
        ll cnt = 0;
        bool ok = 1;
        for(int i = 0; i < n; i++){
            //cout<<curr<<" ";
            if(abs(v[i] - curr) <= 1){
                cnt += abs(v[i] - curr);
            }
            else
                ok = 0;
            curr += dx;
        }
        //cout<<endl;
        if(ok)
            ans = min(ans, cnt);
    }
    cout<<((ans == INF) ? -1 : ans)<<endl;
    return 0;
}
