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
    vector<bool> vis(101);
    for(int i = a; i < b; i++)
        vis[i] = 1;
    for(int i = c; i < d; i++)
        vis[i] = 1;
    int ans = 0;
    for(bool x: vis)
        if(x)
            ans++;
    cout<<ans<<endl;
    return 0;
}
