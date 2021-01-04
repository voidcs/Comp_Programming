#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/734/B

int main(){
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int ans = 0;
    int x = min({a, c, d});
    for(int i = 0; i < x; i++){
        ans += 256;
    }
    a -= x;
    for(int i = 0; i < min(a, b); i++){
        ans += 32;
    }
    cout<<ans<<endl;
    
    return 0;
}