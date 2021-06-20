#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, a, b;
        cin>>n>>a>>b;
        if(a*2 <= b){
            cout<<n*a<<endl;
        }
        else{
            ll ans = b * (n/2);
            ans += (n%2) * a;
            cout<<ans<<endl;
        }
    }
    return 0;
}
