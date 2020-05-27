#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    ll x;
    ll base;
    cout<<"Enter the base 10 number to be converted\n";
    cin>>x;
    
    cout<<"Enter the base to convert to\n";
    cin>>base;
    
    vector<char> v;
    
    cout<<x<<" in base: "<<base<<" is: ";
    while(x){
        ll add = 0;
        if(x%base > 9)
            add = 7;
        v.push_back('0' + (x%base) + add);
        x /= base;
    }
    
    reverse(v.begin(), v.end());
   
    for(auto x: v)
        cout<<x;

  return 0;
}

