#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    bool flag = 0;
    for(int i = 1; i <= 500; i++){
        ll x = (i*(i+1))/2;
        flag ^= (x == n);
    }
    if(flag)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}