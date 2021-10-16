#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    multiset<ll> s;
    for(ll &x: v){
        cin>>x;
        s.insert(x);
    }
    vector<ll> ans, curr;
    function<void(ll)> dfs = [&](ll u){
        if(s.empty()){
            ans = curr;
            return;
        }
        if(s.count(u*2)){
            s.erase(s.lower_bound(u*2));
            curr.push_back(u*2);
            dfs(u*2);
            curr.pop_back();
            s.insert(u*2);
        }
        if(u%3 == 0 && s.count(u/3)){
            ll x = u/3;
            s.erase(s.lower_bound(x));
            curr.push_back(x);
            dfs(x);
            curr.pop_back();
            s.insert(x);
        }
    };
    for(int i = 0; i < n; i++){
        s.erase(s.lower_bound(v[i]));
        curr.push_back(v[i]);
        dfs(v[i]);
        curr.pop_back();
        s.insert(v[i]);
    }
    for(ll x: ans)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}
