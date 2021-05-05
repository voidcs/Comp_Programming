#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

struct rect{
    int x1, x2, y1, y2;
};

int main(){
    rect w, a, b;
    cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    
    auto coveredCorner = [&](int x, int y, rect a){
        return x >= a.x1 && x <= a.x2 && y >= a.y1 && y <= a.y2;
    };
    int firstCover = 0, secondCover = 0;
    firstCover += coveredCorner(w.x1, w.y1, a);
    firstCover += coveredCorner(w.x2, w.y1, a);
    firstCover += coveredCorner(w.x1, w.y2, a);
    firstCover += coveredCorner(w.x2, w.y2, a);
    
    secondCover += coveredCorner(w.x1, w.y1, b);
    secondCover += coveredCorner(w.x2, w.y1, b);
    secondCover += coveredCorner(w.x1, w.y2, b);
    secondCover += coveredCorner(w.x2, w.y2, b);
    
    int bothCover = 0;
    if(coveredCorner(w.x1, w.y1, a) || coveredCorner(w.x1, w.y1, b))
        bothCover++;
    if(coveredCorner(w.x2, w.y2, a) || coveredCorner(w.x2, w.y2, b))
        bothCover++;
    if(coveredCorner(w.x1, w.y2, a) || coveredCorner(w.x1, w.y2, b))
        bothCover++;
    if(coveredCorner(w.x2, w.y1, a) || coveredCorner(w.x2, w.y1, b))
        bothCover++;

    if(firstCover == 4 || secondCover == 4)
        cout<<"NO\n";
    else if(bothCover < 4)
        cout<<"YES\n";
    else{
        bool valid = (min(a.x2, b.x2) >= max(a.x1, b.x1) && min(a.y2, b.y2) >= max(a.y1, b.y1));
        if(valid)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    
    return 0;
}