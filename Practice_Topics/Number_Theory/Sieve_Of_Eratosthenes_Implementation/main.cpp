#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=1K-NPoepIHc&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=4

bool isPrime[1000001];

void sieve(int n){
    for(int i = 0; i <= n; i++)
        isPrime[i] = 1;
    
    isPrime[0] = isPrime[1] = 0;
    
    for(int i = 2; i*i <= n; i++){
        if(isPrime[i]){
            for(int j = i*i; j <= n; j+=i)
                isPrime[j] = 0;
        }
    }
}

int main(){
    int range;
    cout<<"Enter the upper bound for the sieve\n";
    cin>>range;
    sieve(range);
    
    for(int i = 0; i <= range; i++){
        if(isPrime[i]){
            cout<<i<<" is prime\n";
        }
    }
    
    return 0;
}