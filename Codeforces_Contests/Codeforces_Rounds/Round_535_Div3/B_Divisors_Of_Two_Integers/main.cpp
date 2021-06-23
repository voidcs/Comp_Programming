#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    multiset<ll> key;
    for(ll &x: v){
        cin>>x;
        key.insert(x);
    }
    sort(v.begin(), v.end());
    ll x = v[n-1];
    cout<<x<<" ";
    vector<ll> primeFact;
    for(ll i = 2; i*i <= x; i++){
        while(x % i == 0){
            primeFact.push_back(i);
            x /= i;
        }
    }
    if(x > 1)
        primeFact.push_back(x);
    ll s = primeFact.size();
    set<ll> used;
    for(ll i = 0; i < (1LL<<s); i++){
        ll c = 1;
        for(ll j = 0; j < s; j++){
            if(i & (1LL<<j))
                c *= primeFact[j];
        }
        if(key.count(c) && !used.count(c)){
            key.erase(key.lower_bound(c));
            used.insert(c);
        }
    }
    ll y = 1;
    for(auto t: key)
        y = t;
    cout<<y<<endl;
    return 0;
} 