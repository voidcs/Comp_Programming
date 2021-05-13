#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    vector<vector<char>> v(n*2, vector<char>(m));
    for(int i = 0; i < 2*n; i++)
        for(int j = 0; j < m; j++)
            cin>>v[i][j];
    
    int ans = 0;
    for(int i = 0; i < m; i++){
        //a bitmasks letters present in spotty cow
        //b bitmasks letters present in plain cow
        int a = 0, b = 0;
        for(int j = 0; j < n; j++){
            int x = v[j][i] - 'A';
            a |= (1 << x);
        }
        for(int j = n; j < 2*n; j++){
            int x = v[j][i] - 'A';
            b |= (1 << x);
        }
        if((a & b) == 0)
            ans++;
    }
    cout<<ans<<endl;
    
    return 0;
}