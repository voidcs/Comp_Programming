#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://www.codechef.com/problems/PRB01

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
    cin>>t;
    for(int i = 0; i < t; i++){
        int num;
        cin>>num;
        if(isPrime(num))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}