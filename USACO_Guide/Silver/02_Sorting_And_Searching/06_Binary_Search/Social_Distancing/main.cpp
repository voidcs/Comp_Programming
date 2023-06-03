#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    ll n, m;
    cin>>n>>m;
    vector<array<ll, 2>> v(m);
    for(auto &x: v)
        cin>>x[0]>>x[1];
    sort(v.begin(), v.end());
    ll l = 1, r = INF;
    ll ans = -1;
    auto valid = [&](ll d){
        ll q = n-1;
        ll last = v[0][0];
        int i = 0;
        while(q--){
            if(i == m)
                return false;
            if(last + d > v[i][1]){
                while(i < m && v[i][1] < last + d){
                    i++;
                } 
                if(i == m)
                    return false;
                last = max(last + d, v[i][0]);
            }
            else{
                last += d;
            }
        }
        return true;
    };
    while(l <= r){
        ll mid = (l + r) / 2;
        if(valid(mid)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout<<ans<<"\n";
} 
