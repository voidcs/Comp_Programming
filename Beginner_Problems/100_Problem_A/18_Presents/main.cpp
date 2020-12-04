#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    ll ans[n];
    for(int i = 0; i < n; i++){
        ans[a[i]-1] = i;
    }
    for(int i = 0; i < n; i++)
        cout<<ans[i]+1<<" ";
    return 0;
}