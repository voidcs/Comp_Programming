#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    for(int i = 0; i < (1<<n); i++){
        ll x = i^(i>>1);
        string ans;
        while(x){
            ans += '0' + (x%2);
            x /= 2;
        }
        while(ans.length() != n)
            ans += '0';
        reverse(ans.begin(), ans.end());
        cout<<ans<<endl;
    }
    return 0;
}
