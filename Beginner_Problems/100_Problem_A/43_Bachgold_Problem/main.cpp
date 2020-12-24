#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ll n;
    cin>>n;
    if(n%2 == 0){
        cout<<n/2<<endl;
        for(int i = 0; i < n/2; i++)
            cout<<2<<" ";
    }
    else{
        n -= 3;
        cout<<n/2+1<<endl;
        cout<<"3 ";
        for(int i = 0; i < n/2; i++)
            cout<<"2 ";
    }
    return 0;
}