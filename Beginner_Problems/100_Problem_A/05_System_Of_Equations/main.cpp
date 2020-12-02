#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int n, m;
    cin>>n>>m;
    ll ans = 0;
    for(int i = 0; i <= 1000; i++){
        for(int j = 0; j <= 1000; j++){
            if((i*i)+j == n && (j*j)+i == m)
                ans++;
        }
    }
    cout<<ans;
    
    return 0;
}