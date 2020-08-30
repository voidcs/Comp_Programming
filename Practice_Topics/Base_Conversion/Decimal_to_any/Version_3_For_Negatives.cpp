#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    
    ll x;
    ll base;
    cout<<"Enter the base 10 number to be converted\n";
    cin>>x;
    
    bool flag = 0;
    
    if(x < 0){
        flag = 1;
        x *= -1;
    }
    
    cout<<"Enter the base to convert to\n";
    cin>>base;
    
    vector<char> v;
    
    cout<<x<<" in base: "<<base<<" is: ";
    while(x){
        ll add = 0;
        char start = '0';
        
        int r = x%base;
        if(r > 9){
            start = 'A';
            r -= 10;
        }
        v.push_back(start + r);
        x /= base;
    }
    
    reverse(v.begin(), v.end());
   
    if(flag)
        cout<<"-";
    
    for(auto x: v)
        cout<<x;

  return 0;
}