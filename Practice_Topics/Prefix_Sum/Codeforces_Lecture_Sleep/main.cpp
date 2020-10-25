#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codeforces.com/contest/961/problem/B

int main(){
    ll n, k;
    cin>>n>>k;
    ll a[n+1];
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    ll start = 0;
    ll prefix[n+1];
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        int flag;
        cin>>flag;
        if(flag){
            start += a[i];
            prefix[i] = prefix[i-1];
        }
        else
            prefix[i] = prefix[i-1] + a[i];
    }
    
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(i + k > n)
            break;
        ans = max(ans, start + prefix[i+k] - prefix[i]);
    }
    cout<<ans<<endl;
    
	return 0;
}