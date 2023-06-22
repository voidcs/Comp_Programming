#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    sort(v.begin(), v.end());
    ll minAns = INF, maxAns = 0;
    if(v[n-2] - v[0] == n-2 && v[n-1] - v[n-2] > 2)
        minAns = 2;
    else if(v[n-1] - v[1] == n-2 && v[1] - v[0] > 2)
        minAns = 2;
    else{
        int r = 0;
        int maxRange = 0;
        for(int l = 0; l < n; l++){
            while(r < n - 1 && v[r+1] - v[l] <= n-1)
               r++;
            maxRange = max(maxRange, r - l + 1);
        }
        minAns = n - maxRange;
    }
    maxAns = max(v[n-2] - v[0], v[n-1] - v[1]) - (n - 2);
    cout<<minAns<<endl<<maxAns<<endl;
    return 0;
}
