#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll g = 1, ans = 0;
        auto LCM = [&](ll a, ll b){
            return (a*b) / __gcd(a, b);
        };
        for(int i = 1; i <= n; i++){
            g = LCM(g, i);
            if(g > n)
                break;
            ans += n/g;
        }
        cout<<(ans+n)%mod<<endl;
    }
    return 0;
}