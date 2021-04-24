#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/339/B

int main(){
    ll n, m;
    cin>>n>>m;
    ll ans = 0, c = 1;
    for(int i = 0; i < m; i++){
        ll x;
        cin>>x;
        if(c <= x)
            ans += x-c;
        else
            ans += (n-c)+x;
        c = x;
    }
    cout<<ans<<endl;
    return 0;
}