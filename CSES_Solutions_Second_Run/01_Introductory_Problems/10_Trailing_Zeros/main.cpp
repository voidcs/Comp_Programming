#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ll n;
    cin>>n;
    ll ans = 0;
    for(int i = 5; i <= n; i*=5){
        ans += n/i;
    }
    cout<<ans<<endl;
    
    return 0;
}