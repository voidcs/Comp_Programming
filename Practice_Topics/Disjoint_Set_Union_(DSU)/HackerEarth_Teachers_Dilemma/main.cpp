#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
//PROBLEM LINK
//https://www.hackerearth.com/challenges/competitive/code-monk-disjoint-set-union-union-find/algorithm/teachers-dilemma-3/

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=_0YjD1HcWW8&list=PL2q4fbVm1Ik4JdzE2Bv_UUGBz0TXEIrai&index=5

vector<int> par;

int find(int x){
    return (par[x] < 0) ? x: par[x] = find(par[x]);
}

void unite(int a, int b){
    a = find(a), b = find(b);
    
    if(a != b){
        par[b] += par[a];
        par[a] = b;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n, m;
    cin>>n>>m;
    par = vector<int>(n+1, -1);
    
    int a, b;
    while(m--){
        cin>>a>>b;
        unite(a, b);
    }
    
    ll ans = 1;
    for(int i = 1; i <= n; i++){
        if(par[i] < 0){
            ans = abs(par[i] * ans) % mod;
        }
    }
    
    cout<<ans;
    return 0;
}