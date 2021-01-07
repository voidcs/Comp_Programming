#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int main() { 
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll num = 9, pow = 1;
        while(n > (to_string(num).length()) * num){
            n -= (to_string(num).length()) * num;
            num *= 10;
            pow *= 10;
        }
        ll x = (n-1) / (to_string(num).length());
        ll y = (n-1) % (to_string(num).length());
        pow += x;
        string str = to_string(pow);
        cout<<str[y]<<endl;
    }
    return 0; 
} 