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
    
    auto covered = [&](int x, int y){
        //Returns if the point (x,y) is covered by the cow feed billboard
        return x >= b.x1 && x <= b.x2 && y >= b.y1 && y <= b.y2;
    };
    
    int coveredCorner = 0;
    coveredCorner += covered(a.x1, a.y1);
    coveredCorner += covered(a.x2, a.y2);
    coveredCorner += covered(a.x2, a.y1);
    coveredCorner += covered(a.x1, a.y2);
    //We have to fill the entire lawnmower billboard
    if(coveredCorner < 2){
        cout<<(a.x2 - a.x1) * (a.y2 - a.y1)<<endl;
    }
    //The entire lawnmower billboard is already covered
    else if(coveredCorner == 4){
        cout<<"0\n";
    }
    //Find the intersection and subtract it
    else{
        int ans = (a.x2 - a.x1) * (a.y2 - a.y1);
        //h * w is the area of intersection
        int h = min(a.y2, b.y2) - max(a.y1, b.y1);
        int w = min(a.x2, b.x2) - max(a.x1, b. x1);
        ans -= h * w;
        cout<<ans<<endl;
    }
    
    return 0;
}