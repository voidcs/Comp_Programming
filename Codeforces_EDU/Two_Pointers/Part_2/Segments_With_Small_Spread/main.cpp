#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    map<ll, ll> m;
    ll ans = 0;
    int l = 0;
    for(int r = 0; r < n; r++){
        m[v[r]]++;
        while((*--m.end()).first - (*m.begin()).first > k){
            m[v[l]]--;
            if(m[v[l]] == 0)
                m.erase(v[l]);
            l++;
        }
        ans += r-l+1;
    }
    cout<<ans<<endl;
    return 0;
}