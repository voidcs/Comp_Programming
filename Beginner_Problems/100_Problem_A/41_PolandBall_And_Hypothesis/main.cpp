#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= (int)1e5; i++){
        int x = n*i+1;
        
        auto isPrime = [&](int a){
            if(a == 1)
                return false;
            for(int i = 2; i*i <= a; i++){
                if(a % i == 0)
                    return false;
            }
            return true;
        };
        if(!isPrime(x)){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}