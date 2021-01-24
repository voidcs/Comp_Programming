#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        if(a > b)
            swap(a, b);
        if((a+b)%3 == 0 && a*2 >= b)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    
    return 0;
}
