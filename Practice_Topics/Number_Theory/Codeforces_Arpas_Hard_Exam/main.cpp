#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codeforces.com/contest/742/problem/A
//REFERENCE VIDEO
//https://www.youtube.com/watch?v=21rEmt2J73Q&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=18
ll pow(ll n){
    ll iden = 1;
    ll x = 8;
    while(n){
        if(n%2){
            iden = (iden * x) % 10;
        }
        x = (x*x) % 10;
        n /= 2;
    }
    return iden;
}
int main(){
    ll n;
    cin>>n;
    cout<<pow(n);
    return 0;
}
