#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codeforces.com/contest/1167/problem/C

vector<int> par;
vector<int> cnt;

int find(int x){
    return (par[x] == x) ? x: par[x] = find(par[x]);
}

void unite(int a, int b){
    a = find(a), b = find(b);
    
    if(a != b){
        par[b] = a;
        cnt[a] += cnt[b];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n, m;
    cin>>n>>m;
    par = vector<int>(n + m, 0);
    cnt = vector<int>(n + m, 0);
    
    for(int i = 0; i < n; i++)
        cnt[i] = 1;
    
    iota(par.begin(), par.end(), 0);
    int a;
    for(int i = 0; i < m; i++){
        int k;
        cin>>k;
        for(int j = 0; j < k; j++){
            cin>>a;
            a--;
            unite(a, n + i);
        }
    }
    
    for(int i = 0; i < n; i++){
        cout<<cnt[find(i)]<<" ";
    }
    cout<<endl;
    return 0;
}