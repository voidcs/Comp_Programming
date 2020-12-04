#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        if(str.length() <= 10)
            cout<<str<<endl;
        else{
            cout<<str[0]<<str.length()-2<<str[str.length()-1]<<endl;
        }
    }
    return 0;
}