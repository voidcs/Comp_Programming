#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/and-choice-0e5db566/

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    ll ans = 0;
    for(int i = 31; i >= 0; i--){
        int cnt = 0;
        for(ll x: v){
            if(x & (1LL << i))
                cnt++;
        }
        if(cnt >= 2){
            vector<ll> newV;
            for(ll x: v){
                if(x & (1LL << i))
                    newV.push_back(x);
            }
            v = newV;
        }
        sort(v.rbegin(), v.rend());
        if(v.size() >= 2)
            ans = max(ans, v[0] & v[1]);
    }
    cout<<ans<<endl;
    
    return 0;
}