#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll a, b;
    cin>>a>>b;
    ll ans = 0;
    if(b % a == 0){
        b /= a;
        while(b % 2 == 0){
            ans++;
            b /= 2;
        }
        while(b % 3 == 0){
            ans++;
            b /= 3;
        }
        if(b == 1)
            cout<<ans<<endl;
        else
            cout<<"-1\n";
    }
    else
        cout<<"-1\n";
    return 0;
}