#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
//PROBLEM LINK
//https://codeforces.com/contest/1374/problem/A

int main(){
    ll t;
    scanf("%lld", &t);
    while(t--){
        ll x, y, n;
        scanf("%lld%lld%lld", &x, &y, &n);
        ll r = n%x;
        r -= y;
        if(r < 0)
            r += x;
        printf("%lld\n", n - r);
    }
    return 0;
}