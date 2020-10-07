#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    while(n != 1){
        if(n % 2){
            cout<<n<<" ";
            n = (n*3) + 1;
            
        }
        else{
            cout<<n<<" ";
            n /= 2;
        }
    }
    cout<<1;
    return 0;
}