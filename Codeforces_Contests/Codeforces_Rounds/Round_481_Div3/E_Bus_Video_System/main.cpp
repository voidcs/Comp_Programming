#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, w;
    cin>>n>>w;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    ll upper = -1, lower = -1;
    ll l = 0, r = 1e10;
    auto valid = [&](ll x){
        if(x > w)
            return 2;
        for(int i = 0; i < n; i++){
            x += v[i];
            if(x > w)
                return 2;
            if(x < 0)
                return 3;
        }
        return 1;
    };
    while(l <= r){
        ll m = (l+r)/2;
        ll res = valid(m);
        if(res == 1){
            upper = m;
            l = m+1;
        }
        else if(res == 2){
            r = m-1;
        }
        else if(res == 3){
            l = m+1;
        }
    }
    l = 0, r = 1e10;
    while(l <= r){
        ll m = (l+r)/2;
        ll res = valid(m);
        if(res == 1){
            lower = m;
            r = m-1;
        }
        else if(res == 2){
            r = m-1;
        }
        else if(res == 3){
            l = m+1;
        }
    }
    //cout<<"lower: "<<lower<<" upper: "<<upper<<endl;
    if(upper == -1 || lower == -1){
        cout<<"0\n";
        return 0;
    }
    cout<<max(0LL, upper-lower+1)<<endl;
    return 0;
}
