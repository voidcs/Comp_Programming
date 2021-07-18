#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    int l = 0, r = n-1;
    int ans = 0;
    while(l <= r){
        if(v[l] <= k){
            ans++;
            l++;
        }
        else if(v[r] <= k){
            ans++;
            r--;
        }
        else
            break;
    }
    cout<<ans<<endl;
    return 0;
}
