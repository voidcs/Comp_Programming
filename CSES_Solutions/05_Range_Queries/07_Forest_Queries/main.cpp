#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    vector<vector<int>> pref(n+1, vector<int>(n+1));
    vector<vector<char>> g(n+1, vector<char>(n+1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin>>g[i][j];
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n; j++){
            if(g[i][j] == '*')
                cnt++;
            pref[i][j] = cnt + pref[i-1][j];
        }
    }
    while(q--){
        int y1, x1, y2, x2;
        cin>>y1>>x1>>y2>>x2;
        int ans = pref[y2][x2] + pref[y1-1][x1-1];
        ans -= pref[y1-1][x2] + pref[y2][x1-1];
        cout<<ans<<endl;
    }
    
    return 0;
}