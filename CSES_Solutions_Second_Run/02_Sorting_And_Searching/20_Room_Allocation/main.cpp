#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ll n;
    cin>>n;
    vector<array<ll, 3>> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i][0]>>v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    vector<ll> rooms(n, 0);
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    for(int i = 0; i < n; i++){
        ll t = v[i][0], leave = v[i][1];
        ll person = v[i][2];
        if(!pq.empty() && pq.top()[0] < t){
            rooms[person] = pq.top()[1];
            pq.pop();
            pq.push({leave, rooms[person]});
        }
        else{
            rooms[person] = pq.size() + 1;
            pq.push({leave, (ll)pq.size()+1});
        }
        ans = max(ans, (ll)pq.size());
    }
    cout<<ans<<endl;
    for(auto x: rooms)
        cout<<x<<" ";
    cout<<endl;
    
    return 0;
}