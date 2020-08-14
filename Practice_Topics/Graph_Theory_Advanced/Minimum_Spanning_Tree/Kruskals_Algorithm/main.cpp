#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

//PROBLEM LINK
//https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/
//REFERENCE VIDEO
//https://www.youtube.com/watch?v=XRH1fqAQZrE&list=PL2q4fbVm1Ik64I3VqbVGRfl_OgYzvzt9m&index=3

struct edge{
    int a;
    int b;
    int w;
};

edge ar[100001];
int par[100001];

bool comp(edge a, edge b){
    return (a.w < b.w);
}

int find(int x){
    return (x == par[x]) ? x : par[x] = find(par[x]);
}

void unite(int a, int b){
    par[a] = b;
}

int main(){
    int n, m;
    cin>>n>>m;
    iota(par, par+n+1, 0);
    
    for(int i = 0; i < m; i++){
        int a, b, w;
        cin>>ar[i].a>>ar[i].b>>ar[i].w;
    }
    
    sort(ar, ar + m, comp);
    
    int sum = 0;
    for(int i = 0; i < m; i++){
        int a = find(ar[i].a);
        int b = find(ar[i].b);
        
        if(a != b){
            sum += ar[i].w;
            unite(a, b);
        }
    }
    
    cout<<sum;
    
    return 0;
}