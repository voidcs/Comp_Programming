#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int n;
    cin>>n;
    vector<vector<int>> v(3000, vector<int>(3000, -1));
    map<char, array<int, 2>> m;
    m['N'] = {0, 1};
    m['E'] = {1, 0};
    m['S'] = {0, -1};
    m['W'] = {-1, 0};
    int x = 1500, y = 1500;
    v[x][y] = 0;
    int ans = 1e9;
    int t = 0;
    for(int i = 0; i < n; i++){
        char c;
        int s;
        cin>>c>>s;
        for(int j = 0; j < s; j++){
            x += m[c][0], y += m[c][1];
            t++;
            if(v[x][y] != -1){
                ans = min(ans, t - v[x][y]);
            }
            v[x][y] = t;
        }
    }
    if(ans == 1e9)
		cout<<"-1\n";
    else
        cout<<ans<<endl;
    return 0;
}
