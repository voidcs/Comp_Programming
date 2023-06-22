#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    map<ll, ll> m;
    for(int i = 0; i < n; i++){
        int q;
        cin>>q;
        if(q == 0){
            ll a, b;
            cin>>a>>b;
            m[a] = b;
        }
        else{
            ll a;
            cin>>a;
            cout<<m[a]<<endl;
        }
    }
}