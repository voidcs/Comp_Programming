#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<ll> par;
//PROBLEM LINK
//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/feasible-relations/description/

ll find(ll x){
    return (x == par[x]) ? x : par[x] = find(par[x]);
}

void unite(ll x, ll y){
    x = find(x), y = find(y);
    //cout<<"X: "<<x<<"  Y: "<<y<<endl;
    if(x != y){
        par[x] = y;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t;
    cin>>t;
    while(t--){
        vector<pair<ll, ll>> v;
        ll n, k;
        cin>>n>>k;
        par = vector<ll> (n+k+5, 0);
        iota(par.begin(), par.end(), 0);
        
        for(int i = 0; i < k; i++){
            ll x, y;
            string str;
            cin>>x>>str>>y;
            if(str == "!="){
                v.push_back({x,y});
            }
            else{
                unite(x, y);
            }
        }

        bool flag = 1;
        for(int i = 0; i < v.size(); i++){
            ll x = v[i].first;
            ll y = v[i].second;
            
            if(find(par[x]) == find(par[y]))
                flag = 0;
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        
    }
    return 0;
}