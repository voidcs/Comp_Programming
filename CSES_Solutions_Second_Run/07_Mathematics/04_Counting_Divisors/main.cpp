#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    int maxN = 1e6+5;
    vector<int> lpf(maxN, 0);
    for(ll i = 2; i < maxN; i++){
        if(!lpf[i]){
            lpf[i] = i;
            for(ll j = i*i; j < maxN; j += i){
                if(lpf[j] == 0)
                    lpf[j] = i;
            }
        }
    }
    ll t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        map<int, int> m;
        while(x > 1){
            m[lpf[x]]++;
            x /= lpf[x];
        }
        ll ans = 1;
        for(auto x: m){
            ans *= x.second+1;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}