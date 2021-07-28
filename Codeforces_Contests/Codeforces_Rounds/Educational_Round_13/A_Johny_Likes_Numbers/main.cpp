#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, k;
    cin>>n>>k;
    if(n%k == 0)
        cout<<n+k<<endl;
    else{
        cout<<n + (k - (n%k))%k<<endl;
    }
    return 0;
}
