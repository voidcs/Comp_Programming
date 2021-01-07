#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    for(int i = 0; i < 1<<n; i++){
        //Corresponding number
        ll x = (i ^ (i>>1));
        string s;
        //Convert back to binary
        while(x){
            s += '0' + (x%2);
            x /= 2;
        }
        while(s.length() != n)
            s += '0';
        reverse(s.begin(), s.end());
        cout<<s<<endl;
    }
    
    return 0;
}