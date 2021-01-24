#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    ll sum = 0;
    for(int i = 0; i < n-1; i++){
        ll x;
        cin>>x;
        sum += x;
    }
    cout<<((n*(n+1))/2) - sum<<endl;
    return 0;
}
