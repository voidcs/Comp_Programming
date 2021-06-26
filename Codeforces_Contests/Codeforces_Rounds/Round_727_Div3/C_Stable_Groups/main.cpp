#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, k, x;
    cin>>n>>k>>x;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    sort(v.begin(), v.end());
    vector<ll> gaps;
    for(int i = 0; i < n; i++){
        int j = i + 1;
        while(j < n && v[j] - v[i] <= x){
            j++, i++;
        }
        if(j < n)
            gaps.push_back(v[j] - v[i]);
    }
    ll ans = gaps.size()+1;
    sort(gaps.begin(), gaps.end());
    for(int i = 0; i < gaps.size(); i++){
        gaps[i] -= (2*x);
        ll need = (gaps[i]+x-1)/x;
        need++;
        if(k >= need){
            ans--;
            k -= need;
        }
    }
    cout<<ans<<endl;

    return 0;
}
