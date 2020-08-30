#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> cnt;
vector<int> par;

//PROBLEM LINK
//https://codeforces.com/contest/1249/problem/B2

int find(int x){
    return (x == par[x] ? x : par[x] = find(par[x]));
}

int unite(int x, int y){
    x = find(x), y = find(y);
    if(x != y){
        par[x] = y;
        cnt[y] += cnt[x];
    }
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++){
            cin>>a[i]; 
        }
        par = vector<int> (2*n, 0);
        cnt = vector<int> (2*n, 1);
        iota(begin(par), end(par), 0);

        for(int i = 0; i < n; i++){
            unite(i, a[i]-1);
        }

        for(int i = 0; i < n; i++){
            cout<<cnt[find(i)]<<" ";
        }
        cout<<endl;
    }
    return 0;
}