#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

struct rect{
    int x1, x2, y1, y2;
};

int main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    rect a, b;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    int h = max(a.x2, b.x2) - min(a.x1, b.x1);
    int w = max(a.y2, b.y2) - min(a.y1, b.y1);
    int ans = max(h, w);
    ans *= ans;
    cout << ans << endl;
    
    return 0;
}