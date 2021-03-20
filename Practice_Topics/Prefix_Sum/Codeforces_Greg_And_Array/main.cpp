#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

//PROBLEM LINK
//https://codeforces.com/contest/295/problem/A

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, k;
    cin>>n>>m>>k;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    vector<array<ll, 3>> op(m);
    for(int i = 0; i < m; i++){
        cin>>op[i][0]>>op[i][1]>>op[i][2];
    }
    vector<ll> freq(m+1);
    for(int i = 0; i < k; i++){
        ll x, y;
        cin>>x>>y;
        x--, y--;
        freq[x]++, freq[y+1]--;
    }
    vector<ll> dx(n+1);
    ll x = 0;
    for(int i = 0; i < m; i++){
        ll l = op[i][0], r = op[i][1], d = op[i][2];
        l--, r--;
        x += freq[i];
        d *= x;
        dx[l] += d, dx[r+1] -= d;
    }
    
    ll prefix = 0;
    for(int i = 0; i < n; i++){
        prefix += dx[i];
        cout<<a[i] + prefix<<" ";
    }
    cout<<endl;
    
    return 0;
}