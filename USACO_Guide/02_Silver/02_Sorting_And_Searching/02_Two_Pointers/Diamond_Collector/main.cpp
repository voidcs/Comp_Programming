#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    ll n, k;
    cin>>n>>k;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    sort(v.begin(), v.end());
    int l = 0, r = 0;
	//Range of the ith diamond
    vector<ll> range(n);
    while(l < n){
        while(r+1 < n && v[r+1] - v[l] <= k)
            r++;
        range[l] = r - l + 1;
        l++;
    }
	//What's the longest segment from the ith point to the end
	//This lets us try segment i and then take the next longest segment after segment i ends
    vector<ll> maxAfter(n+1);
    maxAfter[n] = 0;
    for(int i = n-1; i >= 0; i--){
        maxAfter[i] = max(maxAfter[i+1], range[i]);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, range[i] + maxAfter[i + range[i]]);
    }
    cout<<ans<<endl;
    return 0;
}
