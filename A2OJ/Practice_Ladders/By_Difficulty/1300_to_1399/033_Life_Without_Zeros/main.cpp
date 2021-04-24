#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/75/A

int main(){
    int a[3];
    cin>>a[0]>>a[1];
    a[2] = a[0]+a[1];
    for(int i = 0; i < 3; i++){
        int p = 1, x = 0;
        while(a[i]){
            int d = a[i]%10;
            if(d){
                x += d*p;
                p *= 10;
            }
            a[i] /= 10;
        }
        a[i] = x;
    }
    if(a[0] + a[1] == a[2])
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}