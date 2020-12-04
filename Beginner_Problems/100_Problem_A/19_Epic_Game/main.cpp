#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a, b, n;
    cin>>a>>b>>n;
    bool flag = 1;
    while(n >= 0){
        if(flag)
            n -= __gcd(a, n);
        else
            n -= __gcd(b, n);
        flag = !flag;
        if(n < 0){
            if(flag)
                cout<<"0\n";
            else
                cout<<"1\n";
            return 0;
        }
    }
    return 0;
}