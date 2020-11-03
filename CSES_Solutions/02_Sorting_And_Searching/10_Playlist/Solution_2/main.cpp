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
    
    map<ll, ll> m;
    ll j = 0, ans = 0;
    
    for(int i = 0; i < n; i++){
        while(j < n && m[a[j]] < 1){
            m[a[j]]++;
            j++;
        }
        ans = max(ans, j-i);
        m[a[i]]--;
    }
    cout<<ans<<endl;
    
    return 0;
}