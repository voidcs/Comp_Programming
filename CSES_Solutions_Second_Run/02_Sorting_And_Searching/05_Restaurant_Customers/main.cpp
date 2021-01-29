#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
    for(int i = 0; i < n; i++){
        ll a, b;
        cin>>a>>b;
        pq.push({a, 1});
        pq.push({b, 0});
    }
    ll ans = 0, curr = 0;
    while(!pq.empty()){
        ll u = pq.top()[0];
        ll enter = pq.top()[1];
        pq.pop();
        if(enter){
            curr++;
        }
        else
            curr--;
        ans = max(curr, ans);
    }
    cout<<ans<<endl;
    
    return 0;
}