#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n, q;
    cin>>n>>q;
    ll a[n];
    ll pref[n+1];
    pref[0] = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        pref[i+1] = pref[i] + a[i];
    }
    while(q--){
        int l, r;
        cin>>l>>r;
        l--, r--;
        cout<<pref[r+1] - pref[l]<<endl;
    }
    return 0;
}
