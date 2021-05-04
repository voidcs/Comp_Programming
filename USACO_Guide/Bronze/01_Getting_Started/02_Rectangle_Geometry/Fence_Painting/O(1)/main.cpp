#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a, b, c, d;
    cin>>a>>b>>c>>d;
	//Add the total length from right most point to left most point
    int ans = max(d, b) - min(a, c);
	//Subtract intersection
    ans -= max(0, max(a, c) - min(d, b));
    cout<<ans<<endl;
    return 0;
}
