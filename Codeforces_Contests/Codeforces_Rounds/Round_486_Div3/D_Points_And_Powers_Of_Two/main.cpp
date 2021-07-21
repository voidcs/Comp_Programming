#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<ll> v(n);
    set<ll> s;
    for(ll &x: v){
        cin>>x;
        s.insert(x);
    }
    sort(v.begin(), v.end());
    vector<ll> ans = {v[0]};
    for(ll i = 0; i <= 32; i++){
        ll x = (1LL<<i);
        set<ll> used;
        for(int i = 0; i < n; i++){
            vector<ll> t;
            if(used.count(v[i]))
                continue;
            t.push_back(v[i]);
            used.insert(v[i]);
            ll curr = v[i];
            while(s.count(curr + x)){
                t.push_back(curr + x);
                used.insert(curr + x);
                curr += x;
            }
            if(t.size() > ans.size())
                ans = t;
        }
    }
    while(ans.size() > 3)
        ans.pop_back();
    cout<<ans.size()<<endl;
    for(auto x: ans)
        cout<<x<<" ";
    return 0;
}
