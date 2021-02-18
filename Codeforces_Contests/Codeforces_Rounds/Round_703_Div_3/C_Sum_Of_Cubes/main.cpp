#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    int t;
    cin>>t;
    unordered_set<ll> s;
    ll maxN = 1e12+5;
    for(ll i = 1; i*i*i <= maxN; i++){
        s.insert(i*i*i);
    }
    while(t--){
        ll n;
        cin>>n;
        bool flag = 0;
        for(ll i = 1; i*i*i <= n; i++){
            if(s.count(n-(i*i*i)))
                flag = 1;
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}