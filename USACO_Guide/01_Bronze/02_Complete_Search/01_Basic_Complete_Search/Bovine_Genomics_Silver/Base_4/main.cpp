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
    string dna = "ACGT";
    map<char, int> id;
    for(int i = 0; i < 4; i++)
        id[dna[i]] = i;
    for(int a = 0; a < m; a++){
        for(int b = a + 1; b < m; b++){
            for(int c = b + 1; c < m; c++){
                vector<bool> vis(10000);
                for(int i = 0; i < n; i++){
                    int x = (16 * id[v[i][a]]) + (4 * id[v[i][b]]) + (id[v[i][c]]);
                    vis[x] = 1;
                }
                bool valid = 1;
                for(int i = n; i < 2*n; i++){
                    int x = (16 * id[v[i][a]]) + (4 * id[v[i][b]]) + (id[v[i][c]]);
                    if(vis[x]){
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