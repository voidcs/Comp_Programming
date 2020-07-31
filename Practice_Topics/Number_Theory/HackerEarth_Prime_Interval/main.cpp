#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/prime-interval/

int main(){
    ll l, r;
    cin>>l>>r;
    for(int i = l; i <= r; i++){
        if(i < 2)
            continue;
        
        bool flag = 0;
        for(int j = 2; j*j <= i; j++){
            if(i % j == 0)
                flag = 1;
        }
        if(!flag)
            cout<<i<<" ";
    }
    return 0;
}