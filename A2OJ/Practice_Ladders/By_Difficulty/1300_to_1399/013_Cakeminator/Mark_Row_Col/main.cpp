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
    int x = 0, y = 0;
    vector<int> row(n), col(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'S')
                row[i] = 1, col[j] = 1;
        }
    }
    for(int i = 0; i < n; i++)
        if(row[i])
            x++;
    for(int j = 0; j < m; j++)
        if(col[j])
            y++;
    cout<<(n*m) - (x*y)<<endl;
    return 0;
}

