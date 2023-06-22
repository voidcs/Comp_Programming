#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int x1, x2, y1, y2, h, w;
        cin>>x1>>y1>>x2>>y2>>w>>h;
        if(x2-x1+w > n && y2-y1+h > m){
            cout<<"-1\n";
            continue;
        }
        int ans = 2e9;
        if(x2-x1+w <= n){
            ans = min(w - x1, w - (n-x2));
        }
        if(y2-y1+h <= m)
            ans = min({ans, h - y1, h - (m-y2)});
        ans = max(ans, 0);
        cout<<ans<<endl;
    }
    return 0;
}
