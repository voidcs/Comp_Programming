#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://www.spoj.com/problems/TDKPRIME/

bool isPrime[90000001];
vector<int> primes;

void sieve(int n){
    
    isPrime[0] = isPrime[1] = 1;
    
    for(int i = 2; i*i <= n; i++){
        if(!isPrime[i]){
            for(int j = i*i; j <= n; j+=i)
                isPrime[j] = 1;
        }
    }
    
    for(int i = 0; i <= n; i++){
        if(!isPrime[i]){
            primes.push_back(i);
        }
    }
}

int main(){
    sieve(90000000);
 
    int t;
    scanf("%d", &t);
    while(t--){
        int x;
        scanf("%d", &x);
        printf("%d\n", primes[x-1]);
    }
    
    return 0;
}