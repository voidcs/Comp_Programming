#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    ll even = 0, odd = 0;
    vector<ll> preE(n+1), preO(n+1);
    for(int i = 0; i < n; i++){
        if(i%2)
            odd += v[i];
        else
            even += v[i];
        preE[i+1] = even;
        preO[i+1] = odd;
    } 
    ll ans = 0;
    even = 0, odd = 0;
    for(int i = 0; i < n; i++){
        if(i%2 == 1 || i%2 == 0){
            if(even + preE[n] - preE[i+1] == odd + preO[n] - preO[i+1]){
                ans++;
            }
        }
        if(i%2)
            even += v[i];
        else
            odd += v[i];

    }
    cout<<ans<<endl;
    return 0;
}
