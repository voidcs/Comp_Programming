#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll a[4];
    for(int i = 0; i < 4; i++)
        cin>>a[i];
    ll n;
    cin>>n;
    vector<bool> vis(n+1, 0);
    ll ans = 0;
    for(int i = 0; i < 4; i++){
        for(int j = a[i]; j <= n; j += a[i]){
            if(!vis[j]){
                ans++;
                vis[j] = 1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}