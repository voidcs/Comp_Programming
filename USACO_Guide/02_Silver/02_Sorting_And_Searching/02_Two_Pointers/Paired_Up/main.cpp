#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    ll n;
    cin>>n;
    vector<array<ll, 2>> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i][1]>>v[i][0];
    sort(v.begin(), v.end());
    ll ans = 0;
    ll l = 0, r = n-1;
    while(l <= r){
        if(l == r){
            ans = max(ans, 2*v[l][0]);
            break;
        }
        ans = max(ans, v[l][0] + v[r][0]);
        if(v[l][1] > v[r][1]){
            v[l][1] -= v[r][1];
            r--;
        }
        else if(v[l][1] < v[r][1]){
            v[r][1] -= v[l][1];
            l++;
        }
        else if(v[l][1] == v[r][1]){
            l++, r--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
