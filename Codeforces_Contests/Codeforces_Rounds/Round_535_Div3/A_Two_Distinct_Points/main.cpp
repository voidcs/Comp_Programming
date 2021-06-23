#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        int x = a;
        int y = c;
        if(x == y)
            y++;
        cout<<x<<" "<<y<<endl;
    }
    return 0;
} 