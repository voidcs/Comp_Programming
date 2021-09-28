#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ll n;
    cin>>n;
    ll a[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum += a[i];
    }
    sort(a, a + n);
    cout<<max(sum, a[n-1]*2)<<endl;
    
    return 0;
}