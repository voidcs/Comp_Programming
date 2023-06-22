#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<array<int, 3>> v(k);
    for(int i = 0; i < k; i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    vector<vector<int>> ans(n+1, vector<int>(m+1, 1e9));
    auto valid = [&](int x, int y){
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };
    auto update = [&](int x, int y, int cnt){
        if(valid(x, y))
            ans[x][y] = min(ans[x][y], cnt);
    };
    for(int i = 0; i < k; i++){
        int cnt = 1;
        int x = v[i][0], y = v[i][1];
        ans[x][y] = 1;
        for(int d = 1; d <= 50; d++){
            x--, cnt++;
            if(valid(x, y))
                ans[x][y] = min(ans[x][y], cnt);
            for(int j = 0; j < (2*d)-1; j++){
                y += (v[i][2] == 0) ? 1 : -1;
                cnt++;
                update(x, y, cnt);
            }
            for(int j = 0; j < 2*d; j++){
                x++, cnt++;
                if(valid(x, y))
                    ans[x][y] = min(ans[x][y], cnt);
            }
            for(int j = 0; j < 2*d; j++){
                y += (v[i][2] == 1) ? 1 : -1;
                cnt++;
                update(x, y, cnt);
            }
            for(int j = 0; j < 2*d; j++){
                x--, cnt++;
                update(x, y, cnt);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}