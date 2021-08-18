//https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/B
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
    ll sum = 0, ans = INF, l = 0;
    for(int r = 0; r < n; r++){
        sum += v[r];
        while(sum - v[l] >= s)
            sum -= v[l++];
        if(sum >= s){
            ans = min(ans, r - l + 1);
        }
    }
    cout<< ((ans == INF) ? -1 : ans)<<endl;
    return 0;
}
