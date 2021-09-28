#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a, a + n);
    set<ll> s;
    for(int i = 0; i < n; i++){
        set<ll> temp = s;
        for(auto x: temp)
            s.insert(x+a[i]);
        s.insert(a[i]);
    }
    cout<<s.size()<<endl;
    for(auto x: s)
        cout<<x<<" ";
    cout<<endl;
    
    
    return 0;
}