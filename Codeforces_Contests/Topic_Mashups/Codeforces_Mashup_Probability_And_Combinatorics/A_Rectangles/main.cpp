#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ll ans = 0;
    ll n, m;
    cin>>n>>m;
    ll a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];
    
    for(int i = 0; i < n; i++){
        ll x = 0, y = 0;
        for(int j = 0; j < m; j++){
            if(a[i][j])
                y++;
            else
                x++;
        }
        ans += (1LL << x) - 1;
        ans += (1LL << y) - 1;
    }
    
    for(int i = 0; i < m; i++){
        ll x = 0, y = 0;
        for(int j = 0; j < n; j++){
            if(a[j][i])
                y++;
            else
                x++;
        }
        ans += (1LL << x) - 1;
        ans += (1LL << y) - 1;
    }
    cout<<ans - (n*m)<<endl;
    
    return 0;
}