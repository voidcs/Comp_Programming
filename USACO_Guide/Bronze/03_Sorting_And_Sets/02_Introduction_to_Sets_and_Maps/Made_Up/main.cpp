#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector<int> a(n), b(n), c(n);
    for(int &x: a)
        cin>>x;
    for(int &x: b)
        cin>>x;
    for(int &x: c)
        cin>>x;
    ll ans = 0;
    map<int, int> m, cnt;
    for(int i = 0; i < n; i++)
        m[c[i]-1]++;
    for(int i = 0; i < n; i++)
        cnt[b[i]] += m[i];
    for(int i = 0; i < n; i++)
        ans += cnt[a[i]];
    
    cout<<ans<<endl;
    
    return 0;
}