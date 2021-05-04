#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

struct square{
    int x1, x2, y1, y2;
};

int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    square a[3];
    for(int i = 0; i < 3; i++){
        cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
    }
    for(int i = 0; i < 3; i++){
        a[i].x1 += 1000;
        a[i].x2 += 1000;
        a[i].y1 += 1000;
        a[i].y2 += 1000;
    }
    vector<vector<int>> g(2001, vector<int>(2001));
    for(int i = 0; i < 2; i++){
        for(int x = a[i].x1; x < a[i].x2; x++){
            for(int y = a[i].y1; y < a[i].y2; y++){
                g[x][y] = 1;
            }
        }
    }
    for(int i = a[2].x1; i < a[2].x2; i++){
        for(int j = a[2].y1; j < a[2].y2; j++){
            g[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i = 0; i < g.size(); i++){
        for(int j = 0; j < g[0].size(); j++){
            if(g[i][j])
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}