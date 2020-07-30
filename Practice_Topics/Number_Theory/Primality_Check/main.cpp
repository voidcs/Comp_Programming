#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=ga9N_ey4La4&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=2

bool isPrime(int num){
    if(num == 1)
        return false;
    for(int i = 2; i*i <= num; i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

int main(){
    int t;
    cout<<"Enter the number of test cases\n";
    cin>>t;
    while(t--){
        int num;
        cout<<"Enter a number to test\n";
        cin>>num;
        if(isPrime(num))
            cout<<num<<" is prime\n";
        else
            cout<<num<<" is not a prime number\n";
    }
    return 0;
}