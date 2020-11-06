#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e10;

//PROBLEM LINK
//https://codeforces.com/contest/729/problem/C

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, k, s, t;
    cin>>n>>k>>s>>t;
    pair<ll, ll> a[n];
    ll b[k+2];
    b[0] = 0, b[k+1] = s;
    for(int i = 0; i < n; i++)
        cin>>a[i].first>>a[i].second;
    for(int i = 1; i <= k; i++)
        cin>>b[i];
    
    auto valid = [&](ll x){
        ll time = 0;
        for(int i = 1; i <= k+1; i++){
            ll dist = b[i] - b[i-1];
            if(dist > x)
                return false;
            else if(x >= 2*dist)
                time += dist;
            else{
                ll b = x - dist;
                ll a = dist - b;
                time += (a*2 + b);
            }
            if(time > t)
                return false;
        }
        return true;
    };
    
    sort(b, b + k+2);
    ll l = 0, r = INF;
    ll ans = INF;
    while(l <= r){
        ll mid = (l+r)/2;
        if(valid(mid)){
            r = mid-1;
            ans = mid;
        }
        else
            l = mid+1;
    }
    
    ll best = INF;
    for(int i = 0; i < n; i++){
        if(a[i].second >= ans)
            best = min(best, a[i].first);
    }
    if(best == INF)
        cout<<"-1\n";
    else
        cout<<best<<endl;
    
    return 0;
}