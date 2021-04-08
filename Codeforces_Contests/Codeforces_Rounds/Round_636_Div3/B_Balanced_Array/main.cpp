#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%4 == 0){
            cout<<"YES\n";
            int x = 2;
            for(int i = 0; i < n/4; i++){
                cout<<x<<" "<<x+2<<" ";
                x += 6;
            }
            x = 1;
            for(int i = 0; i < n/4; i++){
                cout<<x<<" "<<x+4<<" ";
                x += 6;
            }
            cout<<endl;
        }
        else
            cout<<"NO\n";
    }
    return 0;
}