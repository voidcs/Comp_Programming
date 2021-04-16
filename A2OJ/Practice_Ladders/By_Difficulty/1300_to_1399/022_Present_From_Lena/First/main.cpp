#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//PROBLEM LINK
//https://codeforces.com/contest/118/problem/B

int main(){
    int n;
    cin>>n;
    int m = (2*n)+1;
    vector<vector<int>> v(m, vector<int>(m, -1));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= i; j++){
            v[i][n-j] = i-j;
            v[i][n+j] = i-j;
        }
    }
    for(int i = 0; i < n; i++){
        v[m-1-i] = v[i];
    }
   
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == -1)
                cout<<" ";
            else
                cout<<v[i][j];
            if(i <= n && j == n+i)
                break;
            if(i > n && j == m - (i - n) - 1)
                break;
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
 