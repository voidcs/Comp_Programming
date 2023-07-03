#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

int main(){
    int n;
    cin>>n;
    function<int(int, int)> gcd = [&](int a, int b){
        if(b == 0)
            return a;
        return gcd(b, a % b);
    };
    vector<int> coprime = {1};
    ll p = 1;
    for(int i = 2; i < n; i++){
        if(gcd(i, n) == 1){
            coprime.push_back(i);
            p = (p * i) % n;
        }
    }
    int ans = coprime.size();
    if(p != 1){
        ans--;
    }
    cout<<ans<<"\n";
    for(int x: coprime){
        if(p != 1 && x == p)
            continue;
        cout<<x<<" ";
    }
    cout<<"\n";
}
