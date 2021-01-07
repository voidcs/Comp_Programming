#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    multiset<ll> s;
    for(int i = 0; i < n; i++){
        if(!i){
            s.insert(a[i]);
            continue;
        }
        auto it = s.upper_bound(a[i]);
        if(it == s.end()){
            s.insert(a[i]);
        }
        else{
            s.erase(s.lower_bound(*it));
            s.insert(a[i]);
        }
    }
    cout<<s.size()<<endl;
    
    return 0;
}