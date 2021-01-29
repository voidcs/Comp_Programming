#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    array<ll, 2> a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i][1]>>a[i][0];
    }
    sort(a, a + n);
    ll ans = 0;
    ll end = 0;
    for(int i = 0; i < n; i++){
        if(a[i][1] >= end){
            ans++;
            end = a[i][0];
        }
    }
    cout<<ans<<endl;
    
    return 0;
}