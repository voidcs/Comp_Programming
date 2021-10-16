#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, m;
    cin>>n>>m;
    ll ans = INF;
    queue<array<ll, 2>> q;
    set<ll> vis;
    q.push({n, 0});
    while(q.size()){
        ll u = q.front()[0];
        ll steps = q.front()[1];
        q.pop();
        if(vis.count(u))
            continue;
        vis.insert(u);
        if(u == m){
            ans = steps;
            break;
        }
        if(!vis.count(u*2) && u*2 < m*2)
            q.push({u*2, steps+1});
        if(u > 1 && u < m && !vis.count(u-1))
            q.push({u-1, steps+1});
        else if(u > m){
            ans = min(ans, steps + (u-m));
        }
    }
    cout<<ans<<endl;
    return 0;
}
