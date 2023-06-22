#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

struct rect{
    int x1, x2, y1, y2;
    int area(){
        return (x2 - x1) * (y2 - y1);
    }
};
int intersect(rect a, rect b){
    return max(0, min(a.y2, b.y2) - max(a.y1, b. y1)) * max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
}

int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    rect a, b, t;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
    int ans = a.area() + b.area();
    ans -= intersect(a, t);
    ans -= intersect(b, t);
    cout << ans << endl;
    return 0;
}