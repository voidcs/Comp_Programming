#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin>>n;
    ll ans = 0;
    while(n--){
        int x;
        int count = 0;
        for(int i = 0; i < 3; i++){
            cin>>x;
            count += x;
        }
        if(count >= 2)
            ans++;
    }
    cout<<ans;
    return 0;
}