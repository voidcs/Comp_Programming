#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        string end;
        cin>>end;
        int ans = 0;
        string x = "1";
        while(x != end){
            ans += x.length();
            if(x.length() >= 4){
                x = x[0] + 1;
            }
            else{
                x += x[0];
            }
        }
        ans += end.length();
        cout<<ans<<endl;
    }
    
    return 0;
}