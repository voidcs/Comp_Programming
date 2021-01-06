#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1351/B

int main(){
    int t;
    cin>>t;
    while(t--){
        ll a, b, c, d;
        cin>>a>>b>>c>>d;
        if(a > b)
            swap(a, b);
        if(c > d)
            swap(c, d);
        if(a+c == b && b==d)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}