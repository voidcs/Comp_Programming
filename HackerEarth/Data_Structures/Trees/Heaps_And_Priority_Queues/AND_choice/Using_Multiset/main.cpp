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
    multiset<ll, greater<ll>> s;
    for(ll &x: v){
        cin>>x;
        s.insert(x);
    }
    ll ans = 0;
    for(int i = 31; i >= 0; i--){
        int cnt = 0;
        for(ll x: s){
            if(x & (1LL << i))
                cnt++;
        }
        if(cnt >= 2){
            auto it = s.begin();
            while(it != s.end()){
                if((*it & (1LL << i)) == 0)
                    s.erase(it++);
                else
                    it++;
            }
        }
        if(s.size() >= 2)
            ans = max(ans, *s.begin() & *(++s.begin()));
    }
    cout<<ans<<endl;
    
    return 0;
}