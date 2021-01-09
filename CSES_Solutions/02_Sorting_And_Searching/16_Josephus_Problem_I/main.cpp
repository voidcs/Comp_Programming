#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    set<ll> s;
    for(int i = 1; i <= n; i++){
        s.insert(i);
    }
    auto it = s.begin();
    for(int i = 0; i < n; i++){
        ll last = 0;
        it++;
        if(it == s.end())
            it = s.begin();
        last = *it;
        it++;
        if(it == s.end())
            it = s.begin();
        cout<<last<<" ";
        s.erase(last);
    }
    
    return 0; 
} 