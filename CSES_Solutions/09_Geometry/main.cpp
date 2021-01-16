#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

struct P{
    ll x, y;
    void read(){
        cin>>x>>y;
    }
    P operator - (P b){
        return P{x - b.x, y - b.y};
    }
    void operator -=(P b){
        x -= b.x;
        y -= b.y;
    }
    ll operator *(const P b) const{
        return x * b.y - y * b.x;
    } 
};

int main(){
    ll t;
    cin>>t;
    while(t--){
        P p1, p2, p3;
        p1.read();
        p2.read();
        p3.read();
        p3 -= p1;
        p2 -= p1;
        
        ll cross_product = (p2 * p3);
        if(cross_product == 0)
            cout<<"TOUCH\n";
        else if(cross_product > 0)
            cout<<"LEFT\n";
        else
            cout<<"RIGHT\n";
    }
    return 0; 
}