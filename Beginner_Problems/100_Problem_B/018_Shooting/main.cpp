#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1216/B

int main(){
    int n;
    cin>>n;
    array<int, 2> a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i][0];
        a[i][1] = i+1;
    }
    sort(a, a + n);
    reverse(a, a + n);
    ll ans = 0;
    vector<ll> order;
    for(int i = 0; i < n; i++){
        ans += (i*a[i][0]) + 1;
        order.push_back(a[i][1]);
    }
    cout<<ans<<endl;
    for(auto x: order)
        cout<<x<<" ";
    cout<<endl;
    
    
    return 0;
}