#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll a, b, c;
    cin>>a>>b>>c;
    ll ans = 0;
    while(~a){
        if(b >= a*2 && c >= a*4){
            ans = a + a*2 + a*4;
            cout<<ans<<endl;
            return 0;
        }
        a--;
    }
    return 0;
}