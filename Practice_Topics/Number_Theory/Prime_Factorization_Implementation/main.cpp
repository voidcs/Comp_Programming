#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=geLyvdjxQNg&list=PL2q4fbVm1Ik4liHX78IRslXzUr8z5QxsG&index=6

void primeFact(ll n){
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            int count = 0;
            while(n % i == 0){
                count++;
                n /= i;
            }
            cout<<i<<" ^ "<<count<<endl;
        }
    }
    if(n > 1){
        cout<<n<<" ^ "<<1<<endl;
    }
}

int main(){
    int t;
    cout<<"ENTER THE NUMBER OF TEST CASES\n";
    cin>>t;
    while(t--){
        ll num;
        cin>>num;
        primeFact(num);
        cout<<endl;
    }
    return 0;
}