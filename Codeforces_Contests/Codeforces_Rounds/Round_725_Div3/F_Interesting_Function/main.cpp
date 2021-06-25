#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll a, b;
        cin>>a>>b;
        auto get = [&](ll x)->ll{
            ll len = 1, sum = 0;
            while(x){
                ll add = 0, p = 1;
                for(int i = 0; i < len; i++){
                    add += p;
                    p *= 10;
                }
                sum += (add * (x%10));
                x /= 10;
                len++;
            }
            return sum;
        };
        cout<<get(b) - get(a)<<endl;
    }
    return 0;
}
