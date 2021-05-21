#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    vector<vector<char>> v(8, vector<char>(8));
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin>>v[i][j];
    int ans = 0;
    vector<int> p(8);
    iota(p.begin(), p.end(), 0);
    do{
        vector<bool> vis(16);
        bool ok = 1;
        for(int i = 0; i < 8; i++){
            if(vis[8 + p[i] - i] || v[i][p[i]] == '*')
                ok = 0;
            vis[8 + p[i] - i] = 1;
        }
        vector<bool> vis2(16);
        for(int i = 0; i < 8; i++){
            if(vis2[p[i] + i])
                ok = 0;
            vis2[p[i] + i] = 1;
        }
        if(ok)
            ans++;
    }while(next_permutation(p.begin(), p.end()));
    cout<<ans<<endl;
    
    return 0;
}