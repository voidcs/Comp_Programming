#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    ll sum = n*(n+1)/2;
    if(sum%2 == 0){
        set<ll> s1, s2;
        ll x = n;
        ll temp = sum/2;
        while(temp >= x){
            s1.insert(x);
            temp -= x;
            x--;
        }
        if(temp)
            s1.insert(temp);
        for(int i = 1; i <= n; i++){
            if(!s1.count(i))
                s2.insert(i);
        }
        cout<<"YES\n";
        cout<<s1.size()<<endl;
        for(auto x: s1)
            cout<<x<<" ";
        cout<<endl;
        cout<<s2.size()<<endl;
        for(auto x: s2)
            cout<<x<<" ";
        cout<<endl;
    }
    else
        cout<<"NO\n";
    return 0;
}
