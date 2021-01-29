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
    ll ans = 1;
    for(int i = 0; i < n; i++){
        if(a[i] <= ans){
            ans += a[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}