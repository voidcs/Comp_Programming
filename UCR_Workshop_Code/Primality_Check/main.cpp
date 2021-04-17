#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
//    Slower way
//    for(int i = 2; i <= n; i++){
//        if(n%i == 0)
//            isPrime = 0;
//    }
    
    //Faster way
    bool isPrime = 1;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0)
            isPrime = 0;
    }
    if(isPrime)
        cout<<n<<" is prime\n";
    else
        cout<<n<<" is not prime\n";

    return 0;
}