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
    vector<int> diag1(16), diag2(16), used(8);
    function<void(int)> dfs = [&](int r){
        if(r == 8){
            ans++;
            return;
        }
        for(int i = 0; i < 8; i++){
            if(!used[i] && v[r][i] == '.' && !diag1[r+i] && !diag2[8+r-i]){
                used[i] = diag1[r+i] = diag2[8+r-i] = 1;
                dfs(r+1);
                used[i] = diag1[r+i] = diag2[8+r-i] = 0;
            }
        }
    };
    dfs(0);
    cout<<ans<<endl;
    
    return 0;
}