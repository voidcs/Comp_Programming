#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1183/B

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        ll a[n];
        for(int i = 0; i < n; i++)
            cin>>a[i];
        sort(a, a + n);
        if(a[n-1] - a[0] > k*2)
            cout<<"-1\n";
        else
            cout<<a[0] + k<<endl;
    }
    
    return 0;
}