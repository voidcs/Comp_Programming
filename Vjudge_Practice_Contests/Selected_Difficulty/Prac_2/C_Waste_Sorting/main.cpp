#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        int c[3];
        int a[5];
        for(int i = 0; i < 3; i++)
            cin>>c[i];
        for(int i = 0; i < 5; i++)
            cin>>a[i];
        for(int i = 0; i < 3; i++)
            c[i] -= a[i];
        
        if(c[0] < 0 || c[1] < 0 || c[2] < 0){
            cout<<"NO\n";
            continue;
        }
        a[3] = max(0, a[3] - c[0]);
        a[4] = max(0, a[4] - c[1]);
        if(a[3] + a[4] > c[2])
            cout<<"NO\n";
        else
            cout<<"YES\n";
        
        
    }
    
    return 0;
}