#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//PROBLEM LINK
//https://www.codechef.com/problems/GCDQ
//Reference video
//https://www.youtube.com/watch?v=qSM02OvsUP8&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=15

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll q, n;
        cin>>n>>q;
        ll a[n];
        for(int i = 0; i < n; i++)
            cin>>a[i];
        ll prefix[n+1], suffix[n+1];
        
        prefix[0] = suffix[n] = 0;
        
        prefix[1] = a[0];
        suffix[n-1] = a[n-1];
        for(int i = 2; i <= n; i++){
            prefix[i] = __gcd(a[i-1], prefix[i-1]);
        }
        
        for(int i = n-2; i >= 0; i--){
            suffix[i] = __gcd(a[i], suffix[i+1]);
        }
        
//        for(int i = 0; i <= n; i++){
//            cout<<prefix[i]<<" ";
//        }
//        cout<<endl;
//        for(int i = 0; i <= n; i++){
//            cout<<suffix[i]<<" ";
//        }
//        cout<<endl;
        
        for(int i = 0; i < q; i++){
            ll l, r;
            cin>>l>>r;
            cout<<__gcd(prefix[l-1], suffix[r])<<endl;
        }
    }
    return 0;
}