#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

struct rect{
    int x1, x2, y1, y2;
};

int main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    rect a, b;
    //a is the lawnmower billboard, b is the cowfeed billboard
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    int ans = (a.x2 - a.x1) * (a.y2 - a.y1);
    
    //If we can cut off a horizontal strip
    if(b.x1 <= a.x1 && a.x2 <= b.x2){
        int d = max(0, min(a.y2, b.y2) - max(a.y1, b.y1));
        //If the cow feed billboard is not completely inside
        if((b.y1 <= a.y1 && b.y2 <= a.y2) || (b.y1 >= a.y1 && b.y2 >= a.y2))
            ans -= d * (a.x2 - a.x1);
    }
    
    //If we can cut off a vertical strip
    if(b.y1 <= a.y1 && a.y2 <= b.y2){
        int d = max(0, min(a.x2, b.x2) - max(a.x1, b.x1));
        //If the cow feed billboard is not completely inside
        if((b.x1 <= a.x1 && b.x2 <= a.x2) || (b.x1 >= a.x1 && b.x2 >= a.x2))
            ans -= d * (a.y2 - a.y1);
    }
    ans = max(ans, 0);
    cout << ans << endl;
    
    return 0;
}