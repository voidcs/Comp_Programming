#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://www.youtube.com/watch?v=K6Raj9Eu2HY&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=9
//https://www.hackerearth.com/practice/math/number-theory/primality-tests/practice-problems/algorithm/micro-and-prime-prime-1/description/

bool isPrime[1000001];
int primePrime[1000001];

void sieve(){
    int maxN = 1e6;
    for(int i = 0; i <= maxN; i++)
        isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    
    for(ll i = 2; i*i <= maxN; i++){
        if(isPrime[i]){
            for(int j = i*i; j <= maxN; j += i){
                isPrime[j] = 0;
            }
        }
    }
    int count = 0;
    for(int i = 0; i <= maxN; i++){
        if(isPrime[i])
            count++;
        if(isPrime[count] == 1){
            primePrime[i] = 1;
        }
        else
            primePrime[i] = 0;
    }
    
    //Stores cumulative sum
    for(int i = 1; i <= maxN; i++){
        primePrime[i] += primePrime[i-1];
    }
}

int main(){
    sieve();
    ll t;
    cin>>t;
    while(t--){
        ll l, r;
        cin>>l>>r;
        cout<<primePrime[r] - primePrime[l-1]<<endl;
    }
    return 0;
}