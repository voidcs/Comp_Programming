#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>v(n);
        vector<ll> m(n, -INF);
        for(ll &x: v)
            cin>>x;
        m[n-1] = v[n-1];
        for(int i = n-2; i >= 0; i--){
            m[i] = min(m[i+1], v[i]);
        }
        ll p = 1;
        ll cnt = 0;
        while(1){
            bool ok = 1;
            ll add = p - 1;
            for(int i = 0; i < n-1; i++){
                if(v[i] > m[i+1] + add)
                    ok = 0;
            }
            if(ok){
                cout<<cnt<<"\n";
                break;
            }
            cnt++;
            p *= 2;
        }
    }
}
