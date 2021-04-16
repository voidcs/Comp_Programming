#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/124/A

int main(){
    int n, a, b;
    cin>>n>>a>>b;
    cout<<min(n-a, b+1);
    return 0;
}