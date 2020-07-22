#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/sum-of-numbers-9/
int main(){
    ll t;
    scanf("%lld", &t);
    while(t--){
        ll n;
        scanf("%lld", &n);
        ll a[n];
        for(int i = 0; i < n; i++)
            scanf("%lld", a + i);
        ll goal;
        scanf("%lld", &goal);
        ll tot = 1 << n;
        bool flag = 0;
        for(int i = 1; i < tot; i++){
            ll sum = 0;
            for(int j = 0; j < n; j++){
                ll f = (1<<j);
                if( (f&i) != 0){
                    sum += a[j];
                }
            }
            if(sum == goal)
                flag = 1;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
