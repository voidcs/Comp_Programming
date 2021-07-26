#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    map<ll, ll> m;
    for(ll &x: v){
        cin>>x;
        m[x]++;
    }
    for(int i = 0; i < n; i++){
        bool ok = 1;
        auto t = m;
        ll x = v[i];
        vector<ll> ans = {x};
        for(int j = 0; j < n-1; j++){
            if(t[x*2] > 0){
                t[x*2]--;
                x *= 2;
            }
            else if(x%3 == 0 && t[x/3] > 0){
                t[x/3]--;
                x /= 3;
            }
            else
                ok = 0;
            ans.push_back(x);
        }
        if(ok){
            for(auto x: ans)
                cout<<x<<" ";
            cout<<endl;
            return 0;
        }
    }

    return 0;
}
