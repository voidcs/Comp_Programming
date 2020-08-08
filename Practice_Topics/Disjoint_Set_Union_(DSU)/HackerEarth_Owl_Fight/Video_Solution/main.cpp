#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/owl-fight/description/

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=wq6TCikSzpk&list=PL2q4fbVm1Ik4JdzE2Bv_UUGBz0TXEIrai&index=7

vector<int> par;

int find(int x){
    return (par[x] < 0) ? x: par[x] = find(par[x]);
}

void unite(int a, int b){
    a = find(a);
    b = find(b);
    
    if(a != b){
        par[a] = min(par[a], par[b]);
        par[b] = a;
    }
}

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    
    int n, m;
    cin>>n>>m;
    par = vector<int>(n+5);
    for(int i = 1; i <= n; i++)
        par[i] = -i;
    
    int a, b;
    while(m--){
        cin>>a>>b;
        unite(a, b);
    }
    
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int x = find(a);
        int y = find(b);
        if(x == y){
            cout<<"TIE\n";
        }
        else{
            if(par[x] < par[y])
                cout<<a<<endl;
            else
                cout<<b<<endl;
        }
    }
    
    return 0;
}