#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    int x, y;
    cin>>x>>y;
    int step = 1, dir = 1, ans = 0;
    while((x < y && x + dir*step < y) || (x > y && x + dir*step > y)){
        ans += 2*step;
        step <<= 1;
        dir *= -1;
    }
    ans += abs(y-x);
    cout<<ans<<endl;
    
    return 0;
}