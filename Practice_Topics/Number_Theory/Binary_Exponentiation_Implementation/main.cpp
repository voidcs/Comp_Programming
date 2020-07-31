#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=8nOaPV-o5Pg&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=7

ll pow(ll base, ll pow){
    ll res = 1;
    while(pow){
        //If the power is odd, multiply the result by the base
        if(pow%2){
            res *= base;
            pow--;
        }
        //If the power is even we can square the base and divide the power by 2
        else{
            base *= base;
            pow /= 2;
        }
    }
    return res;
}

int main(){
    int t;
    cout<<"ENTER THE NUMBER OF TEST CASES\n";
    cin>>t;
    while(t--){
        ll base, power;
        cout<<"Enter the base and the power\n";
        cin>>base>>power;
        cout<<base<<" ^ "<<power<<" = "<<pow(base, power)<<endl;
    }
    return 0;
}