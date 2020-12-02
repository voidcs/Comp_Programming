#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> vis(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>a[i][j];
    
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i][i]){
            vis[i][i] = 1;
            ans += a[i][i];
        }
        if(!vis[n-1-i][i]){
            vis[n-1-i][i] = 1;
            ans += a[n-1-i][i];
        }
    }
    
    for(int i = 0; i < n; i++){
        if(!vis[i][n/2]){
            vis[i][n/2] = 1;
            ans += a[i][n/2];
        }
    }
    for(int i = 0; i < n; i++){
        if(!vis[n/2][i]){
            vis[n/2][i] = 1;
            ans += a[n/2][i];
        }
    }
    cout<<ans<<endl;
    
    return 0;
}