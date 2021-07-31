#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    vector<ll> ans;
    ll add = 0;
    if(n == 1){
        cout<<"0\n";
        cout<<v[0]<<endl;
        return 0;
    }
    for(int i = 1; i < n; i++){
        if(i == 1)
            ans.push_back(v[i-1]);
        ll x = __gcd(v[i], v[i-1]);
        if(x != 1){
            add++;
            ll y = 2;
            while(__gcd(y, v[i]) != 1 || __gcd(y, v[i-1]) != 1){
                y++;
            } 
            ans.push_back(y);
        }
        ans.push_back(v[i]);
    }
    cout<<add<<endl;
    for(auto x: ans)
        cout<<x<<" ";
    return 0;
}
