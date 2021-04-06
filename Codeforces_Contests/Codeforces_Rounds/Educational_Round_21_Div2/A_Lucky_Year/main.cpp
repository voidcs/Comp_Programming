#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n;
    cin>>n;
    ll check = 1;
    bool skip = 0;
    for(int i = 0; i <= 10; i++){
        if(check == n){
            cout<<check<<endl;
            return 0;
        }
        check *= 10;
    }
    if(n <= 9)
        cout<<"1\n";
    else{
        ll pow = 1;
        while(pow < n){
            pow *= 10;
        }
        pow /= 10;
        string s = to_string(n);
        ll next = pow + ((s[0]-'0')*pow);
        cout<<next-n<<endl;
    }
    
    return 0;
}