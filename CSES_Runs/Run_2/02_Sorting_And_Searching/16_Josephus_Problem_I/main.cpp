#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    set<ll> s;
    ll n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        s.insert(i);
    auto it = s.begin();
    while(s.size()){
        it++;
        if(it == s.end()){
            it = s.begin();
        }
        ll x = *it;
        cout<<x<<" ";
        it++;
        s.erase(x);
        if(it == s.end()){
            it = s.begin();
        }
    }
    return 0;
}