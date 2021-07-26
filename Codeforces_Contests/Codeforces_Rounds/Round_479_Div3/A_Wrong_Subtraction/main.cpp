#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll x, k;
    cin>>x>>k;
    while(k--){
        if(x%10 == 0){
            x /= 10;
        }
        else
            x--;
    }
    cout<<x<<endl;
    return 0;
}
