#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codeforces.com/gym/102644/problem/A

int main(){
    long double p;
    ll n;
    cin>>n>>p;
    
    double ans = 1.0;
    while(n){
        if(n%2){
            ans = ans * (1-p) + (1-ans) * p;
            n--;
        }
        else{
            p = (p * (1-p)) * 2;
            n /= 2;
        }
    }
    
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}