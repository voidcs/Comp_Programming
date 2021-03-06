#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%4 != 0){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        ll a = 2, b = 4;
        for(int i = 0; i < n/4; i++){
            cout<<a<<" "<<b<<" ";
            a += 6, b += 6;
        }
        a = 1, b = 5;
        for(int i = 0; i < n/4; i++){
            cout<<a<<" "<<b<<" ";
            a += 6, b += 6;
        }
        cout<<endl;
    }
    
    return 0;
}