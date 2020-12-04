#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m;
    cin>>n>>m;
    int index = 1;
    while(m >= index){
        m -= index;
        index = (index+1) % (n+1);
    }
    cout<<m<<endl;
    
    return 0;
}