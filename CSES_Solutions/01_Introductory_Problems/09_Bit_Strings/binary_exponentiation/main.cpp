#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
 
int main(){
    ll n;
    cin>>n;
    ll ans = 1;
    ll b = 2;
    while(n){
        if(n%2){
            n--;
            ans = (ans * b) % mod;
        }
        b = (b * b) % mod;
        n /= 2;
    }
    cout<<ans % mod<<endl;
    return 0;
}