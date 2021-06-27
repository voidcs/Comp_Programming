#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, k;
    cin>>n>>k;
    if(n < k){
        cout<<"NO\n";
        return 0;
    }
    ll x = (1<<30);
    map<ll, ll> m;
    while(n > 0){
        if(x <= n){
            m[x] += n/x;
        }
        n -= (n/x) * x;
        x >>= 1;
    }

    priority_queue<ll> pq;
    for(auto x: m){
        for(int i = 0; i < x.second; i++){
            pq.push(x.first);
        }
    }
    if(pq.size() > k){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
        while(pq.size() != k){
            ll x = pq.top();
            pq.pop();
            pq.push(x/2);
            pq.push(x/2);
        }
        while(pq.size()){
            cout<<pq.top()<<" ";
            pq.pop();
        }
    }
    return 0;
}
