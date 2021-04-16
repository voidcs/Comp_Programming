#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/168/A

int main(){
    int n, x, y;
    cin>>n>>x>>y;
    int need = ((n*y)+99) / 100;
    cout<<max(0, need-x)<<endl;
    return 0;
}