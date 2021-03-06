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
        int skip = (end[0]-'0')-1;
        for(int i = 0; i < skip; i++){
            ans += (1+2+3+4);
        }
        for(int i = 0; i < end.length(); i++)
            ans += (i+1);
        cout<<ans<<endl;
    }
    
    return 0;
}