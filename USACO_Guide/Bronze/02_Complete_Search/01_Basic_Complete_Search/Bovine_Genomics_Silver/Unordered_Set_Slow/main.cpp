#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    vector<vector<char>> v(n*2, vector<char>(m));
    for(int i = 0; i < 2*n; i++)
        for(int j = 0; j < m; j++)
            cin>>v[i][j];
    int ans = 0;
    for(int a = 0; a < m; a++){
        for(int b = a + 1; b < m; b++){
            for(int c = b + 1; c < m; c++){
                unordered_set<string> s;
                for(int i = 0; i < n; i++){
                    string x;
                    x += v[i][a];
                    x += v[i][b];
                    x += v[i][c];
                    s.insert(x);
                }
                bool valid = 1;
                for(int i = n; i < 2*n; i++){
                    string x;
                    x += v[i][a];
                    x += v[i][b];
                    x += v[i][c];
                    if(s.count(x)){
                        valid = 0;
                        break;
                    }
                }
                if(valid)
                    ans++;
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}