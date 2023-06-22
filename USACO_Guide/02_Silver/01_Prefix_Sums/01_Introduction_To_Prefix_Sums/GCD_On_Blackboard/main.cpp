#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    vector<int> prefix(n+1), suffix(n+1);
    int g = 0;
    for(int i = 0; i < n; i++){
        g = __gcd(g, v[i]);
        prefix[i+1] = g;
    }
    g = 0;
    for(int i = n-1; i >= 0; i--){
        g = __gcd(g, v[i]);
        suffix[i] = g;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int l = prefix[i], r = suffix[i+1];
        ans = max(ans, __gcd(l, r));
    }
    cout<<ans<<endl;
    return 0;
}
