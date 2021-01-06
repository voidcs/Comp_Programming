#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
//PROBLEM LINK
//https://codeforces.com/problemset/problem/1206/B

int main(){
    ll n;
    cin>>n;
    ll a[n];
    ll zeros = 0, ans = 0;
    ll neg = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(a[i] < 0){
            neg++;
            ans += abs(a[i]) - 1;
        }
        else if(a[i] > 0)
            ans += a[i]-1;
        else{
            ans++;
            zeros++;
        }
    }
    if(neg%2 && !zeros)
        ans += 2;
    cout<<ans<<endl;
    
    return 0;
}