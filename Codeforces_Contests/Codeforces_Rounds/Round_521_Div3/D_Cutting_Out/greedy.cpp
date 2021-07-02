#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, k;
    cin>>n>>k;
    vector<ll> v(n);
    map<ll, ll> m, cnt;
    for(ll &x: v){
        cin>>x;
        m[x]++;
    }
    priority_queue<array<ll, 2>> pq;
    for(auto x: m){
        pq.push({x.second, x.first});
        cnt[x.first] = 1;
    }
    vector<ll> ans;
    while(ans.size() != k){
        ll have = pq.top()[0];
        ll x = pq.top()[1];
        pq.pop();
        ans.push_back(x);
        cnt[x]++;
        pq.push({m[x]/cnt[x], x});
    }
    for(auto x: ans)
        cout<<x<<" ";
    cout<<endl;
    
    
    return 0;
}