#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin>>n;
    if(n == 1 || n == 2){
        cout<<"-1\n";
        return 0;
    }
    
    ll b, c;
    if(n % 2){
        b = ((n*n) + 1)/2;
        c = ((n*n) - 1)/2;
    }
    else{
        b = ((n*n)/4) + 1;
        c = (b - 2);
    }
    
    cout<<b<<" "<<c<<endl;
    
    return 0;
}