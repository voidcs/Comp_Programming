#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, x;
    cin>>n>>x;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    //Use prefix sum
    //Denote sum as (# of elements less than x - # of elements greater than x)
    //Store frequency of each prefix sum, if we can find a prefix with (sum-1) or (sum)
    //In our map, then it would make x the median by removing that prefix
    ll ans = 0, sum = 0, has = 0;
    map<int, int> m;
    m[0] = 1;
    for(int i = 0; i < n; i++){
        if(v[i] < x)
            sum--;
        else if(v[i] > x)
            sum++;
        if(v[i] == x)
            has = 1;
        if(has)
            ans += m[sum] + m[sum-1];
        else
            m[sum]++;
    }
    cout<<ans<<endl;
    return 0;
}
