#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1337/B

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x, n, m;
        cin>>x>>n>>m;
        if(x <= m*10){
            cout<<"YES\n";
            continue;
        }
        while(n--){
            x /= 2;
            x += 10;
        }
        if(x <= m*10)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}