#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    vector<vector<ll>> st(30, vector<ll>(n));
    for(int i = 0; i < n; i++)
        st[0][i] = v[i];
    for(int i = 1; i < 30; i++){
        for(int j = 0; j < n; j++){
            if(j+(1<<(i-1)) < n)
                st[i][j] = __gcd(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
    ll l = 0, ans = INF;
    for(int r = 0; r < n; r++){
        auto valid = [&](ll l, ll r){
            ll d = log2(r - l + 1);
            ll x = __gcd(st[d][l], st[d][r-(1<<d)+1]);
            return x == 1;
        };
        while(l+1 <= r && valid(l+1, r)){
            l++;
        }
        if(valid(l, r))
            ans = min(ans, r - l + 1);
    }
    if(ans == INF)
        cout<<"-1\n";
    else
        cout<<ans<<endl;
    return 0;
}