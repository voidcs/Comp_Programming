#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
vector<ll> par;
vector<ll> min_cost;

//PROBLEM LINK
//https://codeforces.com/contest/893/problem/C

ll find(ll x){
    return (x == par[x]) ? x : par[x] = find(par[x]);
}

void unite(ll x, ll y){
    x = find(x), y = find(y);
    if(x != y){
        par[x] = y;
        min_cost[y] = min(min_cost[x], min_cost[y]);
    }
}

int main(){
    ll n, m;
    cin>>n>>m;
    ll a[n+1];
    par = vector<ll>(n+1);
    min_cost = vector<ll>(n+1);
    iota(par.begin(), par.end(), 0);
    
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        min_cost[i] = a[i];
    }
    
    for(int i = 0; i < m; i++){
        ll x, y;
        cin>>x>>y;
        unite(x, y);
    }
    
    ll ans = 0;
    set<ll> s;

    for(int i = 1; i <= n; i++){
        ll p = find(i);
        if(!s.count(p)){
            s.insert(p);
            ans += min_cost[p];
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}