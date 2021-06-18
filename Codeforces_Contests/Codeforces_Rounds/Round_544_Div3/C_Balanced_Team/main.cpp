#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    sort(v.begin(), v.end());
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(pq.size() && v[i] - pq.top() > 5){
            pq.pop();
        }
        pq.push(v[i]);
        ans = max(ans, (int)pq.size());
    }
    cout<<ans<<endl;
    return 0;
}