#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, m;
    cin>>n>>m;
    multiset<ll> s;
    ll x;
    for(int i = 0; i < n; i++){
        cin>>x;
        s.insert(x);
    }
    while(m--){
        cin>>x;
        auto it = s.upper_bound(x);
        if(it == s.begin())
            cout<<"-1\n";
        else{
            it--;
            cout<<*it<<endl;
            s.erase(it);
        }
    }
    return 0;
}