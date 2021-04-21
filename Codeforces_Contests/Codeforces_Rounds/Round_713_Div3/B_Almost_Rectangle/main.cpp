#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/330/A

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<char>> g(n, vector<char>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin>>g[i][j];
        vector<array<int, 2>> v;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(g[i][j] == '*'){
                    v.push_back({i, j});
                }
            }
        }
        if(v[0][1] == v[1][1]){
            int x = v[0][1];
            g[v[0][0]][(x+1)%n] = '*';
            g[v[1][0]][(x+1)%n] = '*';
        }
        else if(v[0][0] == v[1][0]){
            int x = v[0][0];
            g[(x+1)%n][v[0][1]] = '*';
            g[(x+1)%n][v[1][1]] = '*';
        }
        else{
            g[v[0][0]][v[1][1]] = '*';
            g[v[1][0]][v[0][1]] = '*';
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<g[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}