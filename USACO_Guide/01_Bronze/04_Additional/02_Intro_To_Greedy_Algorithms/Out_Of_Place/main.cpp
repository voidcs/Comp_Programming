#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    vector<int> s = v;
    sort(s.begin(), s.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != v[i])
            ans++;
    }
    cout<<ans-1<<endl;
    return 0;
}
