#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n, m, x;
        cin>>n>>m>>x;
        x--;
        int col = x/n;
        int row = x%n;
        ll ans = m*(row);
        ans += col+1;
        cout<<ans<<endl;
    }
    return 0;
}