#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin>>n>>m;
    n++;
    auto isPrime = [&] (int x){
        if(x <= 1)
            return 0;
        for(int i = 2; i*i <= x; i++){
            if(x % i == 0)
                return 0;
        }
        return 1;
    };
    while(!isPrime(n)){
        n++;
    }
    if(n == m)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}