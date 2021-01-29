#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n, x;
    cin>>n>>x;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    map<ll, ll> m;
    for(int i = 0; i < n; i++){
        ll need = x - a[i];
        if(m.count(need)){
            cout<<i+1<<" "<<m[need]+1<<endl;
            return 0;
        }
        m[a[i]] = i;
    }
    cout<<"IMPOSSIBLE\n";
    
    return 0;
}