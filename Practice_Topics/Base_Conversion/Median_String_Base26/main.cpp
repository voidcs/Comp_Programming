#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codeforces.com/contest/1144/problem/E
int main(){
    
    ll n;
    string s, t;
    cin>>n>>s>>t;

    vector<ll> num(n);
    bool borrow = 0;
    
    for(int i = n-1; i >= 0; i--){
        int v = t[i]-s[i]-borrow;
        if(v < 0){
            borrow = 1;
            v += 26;
        }
        else
            borrow = 0;
        num[i] = v;
    }

    ll remainder = 0;
    for(int i = 0; i < n; i++){
        ll v =(remainder*26 + num[i]);
        num[i] = v/2;
        remainder = v%2;
    }

    bool carry = 0;

    for(int i = n-1; i >= 0; i--){
        ll v = (s[i]-'a') + num[i] + carry;
        if(v >= 26){
            v -= 26;
            carry = 1;
        }
        else
            carry = 0;
        
        s[i] = static_cast<char>(v+'a');
    }
    cout<<s;
    
    return 0;
}