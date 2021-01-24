#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    if(n == 1)
        cout<<"1\n";
    else if(n <= 3)
        cout<<"NO SOLUTION\n";
    else{
        for(int i = 2; i <= n; i++){
            if(i%2==0)
                cout<<i<<" ";
        }
        for(int i = 1; i <= n; i++){
            if(i%2)
                cout<<i<<" ";
        }
    }
    return 0;
}
