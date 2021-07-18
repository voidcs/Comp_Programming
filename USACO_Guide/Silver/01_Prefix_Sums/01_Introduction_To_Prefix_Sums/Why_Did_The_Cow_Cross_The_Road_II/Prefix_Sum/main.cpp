#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    int n, k, b;
    cin>>n>>k>>b;
    vector<int> v(n+1, 1);
    v[0] = 0;
    for(int i = 0; i < b; i++){
        int x;
        cin>>x;
        v[x] = 0;
    }
    vector<int> p(n+1);
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += v[i];
        p[i] = sum;
    }
    int ans = 1e9;
    for(int i = 0; i <= n-k; i++){
        ans = min(ans, k - (p[i+k] - p[i]));
    }
    cout<<ans<<endl;
    return 0;
}
