#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    int a, b;
    cin>>a>>b;
    int h = max(a, b);
    int ans = 6 - h + 1;
    int d = __gcd(ans, 6);
    cout<<ans/d<<"/"<<6/d<<endl;
    
    return 0;
}