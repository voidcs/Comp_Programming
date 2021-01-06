#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/contest/1283/problem/B

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        ll each = n/k;
        cout<<min(n, (each*k)+(k/2))<<endl;
    }
    return 0;
}