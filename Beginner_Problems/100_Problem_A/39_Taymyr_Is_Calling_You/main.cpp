#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n, m, z;
    cin>>n>>m>>z;
    ll t = 0;
    ll ans = 0, r = 0;
    bool flag = 0;
    while(t < z){
        t++;
        if(t % m == 0){
            r = 1;
            flag = 1;
        }
        if(!flag)
            r = 0;
        if(t % n == 0){
            ans += r;
            r = 0;
        }
        flag = 0;
    }
    cout<<ans<<endl;
    
    return 0;
}