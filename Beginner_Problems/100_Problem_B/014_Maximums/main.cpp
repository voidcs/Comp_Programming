#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1326/B

int main(){
    int n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    ll x = 0;
    for(int i = 0; i < n; i++){
        cout<<a[i] + x<<" ";
        x = max(x, a[i]+x);
    }
    return 0;
}