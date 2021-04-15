#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/330/A

int main(){
    int n, m;
    cin>>n>>m;
    char a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];
    vector<vector<int>> okay(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        bool valid = 1;
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'S')
                valid = 0;
        }
        if(valid)
            for(int j = 0; j < m; j++)
                okay[i][j] = 1;
    }
    for(int i = 0; i < m; i++){
        bool valid = 1;
        for(int j = 0; j < n; j++){
            if(a[j][i] == 'S')
                valid = 0;
        }
        if(valid)
            for(int j = 0; j < n; j++)
                okay[j][i] = 1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ans += okay[i][j];
    cout<<ans<<endl;

    return 0;
}

