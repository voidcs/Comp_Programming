#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/contest/816/problem/B

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, q;
    cin>>n>>k>>q;
    vector<ll> p(200005), v(200005), ans(200005);
    for(int i = 0; i < n; i++){
        ll a, b;
        cin>>a>>b;
        p[a]++, p[b+1]--;
    }
    ll sum = 0;
    for(int i = 0; i < 200005; i++){
        sum += p[i];
        v[i] = sum;
    }
    sum = 0;
    for(int i = 0; i < 200005; i++){
        if(v[i] >= k)
            sum++;
        ans[i] = sum;
    }
    while(q--){
        ll a, b;
        cin>>a>>b;
        cout<<ans[b] - ans[a-1]<<endl;
    }
    return 0;
}