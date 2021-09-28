#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    while(n != 1){
        cout<<n<<" ";
        if(n%2)
            n = n*3+1;
        else
            n /= 2;
    }
    cout<<n<<endl;
    return 0;
}
