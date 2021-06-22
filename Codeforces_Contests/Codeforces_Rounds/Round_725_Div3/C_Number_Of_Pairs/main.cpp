#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, l, r;
        cin>>n>>l>>r;
        vector<int> v(n);
        for(int &x: v)
            cin>>x;
        sort(v.begin(), v.end());
        ll ans = 0;
        for(int i = 0; i < n; i++){
            int lb = l - v[i];
            int ub = r - v[i];
            int x = lower_bound(v.begin(), v.end(), lb) - v.begin();
            int y = upper_bound(v.begin(), v.end(), ub) - v.begin();
            y--;
            x = max(x, i+1);
            ans += max(y-x+1, 0);
        }
        cout<<ans<<endl;
    }
    return 0; 
} 