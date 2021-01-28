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
    sort(a, a + n);
    ll l = 0, r = n-1;
    ll pairs = 0;
    while(l < r){
        if(a[l]+a[r] <= x){
            pairs++;
            l++, r--;
        }
        else
            r--;
    }
    cout<<n - (pairs*2) + pairs<<endl;
    return 0;
}