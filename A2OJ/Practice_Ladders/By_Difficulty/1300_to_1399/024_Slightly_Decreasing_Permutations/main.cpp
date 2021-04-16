#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/285/A

int main(){
    int n, k;
    cin>>n>>k;
    for(int i = k+1; i >= 1; i--)
        cout<<i<<" ";
    for(int i = k+2; i <= n; i++)
        cout<<i<<" ";

    return 0;
}