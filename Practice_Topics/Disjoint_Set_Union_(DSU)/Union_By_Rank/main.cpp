#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=ryNJby_n3hs&list=PL2q4fbVm1Ik4JdzE2Bv_UUGBz0TXEIrai&index=8

vector<int> par;
vector<int> R;

int find(int x){
    return (par[x] < 0) ? x: par[x] = find(par[x]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a == b){
        return;
    }
    
    //Rank of a is bigger, a becomes parent
    if(R[a] > R[b]){
        par[b] = a;
        R[a] += R[b];
    }
    
    //Rank of b is bigger, b becomes parent
    else{
        par[a] = b;
        R[b] += R[a];
    }
}

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    cout<<"Enter n and m\n";
    int n, m;
    cin>>n>>m;
    par = vector<int>(n);
    R = vector<int>(n);
    
    for(int i = 1; i <= n; i++)
        par[i] = -1, R[i] = 1;
    
    int a, b;
    while(m--){
        cin>>a>>b;
        unite(a, b);
    }
    
    for(int i = 1; i <= n; i++){
        cout<<par[i]<<" ";
    }
    cout<<endl;
    
    for(int i = 1; i <= n; i++){
        cout<<R[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}