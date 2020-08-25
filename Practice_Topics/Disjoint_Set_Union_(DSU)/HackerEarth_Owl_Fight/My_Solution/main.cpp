#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/owl-fight/description/

//REFERENCE VIDEO
//https://www.youtube.com/watch?v=wq6TCikSzpk&list=PL2q4fbVm1Ik4JdzE2Bv_UUGBz0TXEIrai&index=7

vector<int> par;
vector<int> str;

int find(int x){
    return (par[x] == x) ? x: par[x] = find(par[x]);
}

void unite(int a, int b){
    int x = find(a);
    int y = find(b);

    if(x != y){
        par[x] = y;
        str[y] = max(str[y], a);
        str[y] = max(str[y], b);
        str[y] = max(str[y], str[x]);
    }
}

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    int n, m;
    cin>>n>>m;

    str = vector<int>(n+5, 0);
    par = vector<int>(n+5, 0);

    iota(par.begin(), par.end(), 0);
    iota(str.begin(), str.end(), 0);

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
            if(str[x] > str[y])
                cout<<a<<endl;
            else
                cout<<b<<endl;
        }
    }

    return 0;
} 