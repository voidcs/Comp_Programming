//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/A
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, s;
    cin>>n>>s;
    vector<ll> v(n);
    for(ll &x: v)
        cin>>x;
    ll sum = 0, ans = 0, l = 0;
    for(int r = 0; r < n; r++){
        sum += v[r];
        while(sum > s){
            sum -= v[l++];
        }
        ans = max(ans, r - l + 1);
    }
    cout<<ans<<endl;
    return 0;
}
