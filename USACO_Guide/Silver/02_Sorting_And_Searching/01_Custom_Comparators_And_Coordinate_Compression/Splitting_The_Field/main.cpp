#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);
    int n;
    cin>>n;
    vector<array<ll, 2>> v(n);
    //We need the area of using one rectangle
    ll lowX = INF, highX = 0, lowY = INF, highY = 0;
    for(auto &x: v){
        cin>>x[0]>>x[1];
        highX = max(highX, x[0]);
        lowX = min(lowX, x[0]);
        highY = max(highY, x[1]);
        lowY = min(lowY, x[1]);
    }
    ll single = (highX - lowX) * (highY - lowY);
    ll usingTwo = INF;
    sort(v.begin(), v.end());
    auto solve = [&](){
        map<ll, ll> ax, ay, bx, by;
        for(auto x: v){
            bx[x[0]]++;
            by[x[1]]++;
        }
        for(auto x: v){
            ax[x[0]]++, ay[x[1]]++;
            bx[x[0]]--, by[x[1]]--;
            if(bx[x[0]] == 0)
                bx.erase(x[0]);
            if(by[x[1]] == 0)
                by.erase(x[1]);
            if(bx.empty())
                continue;
            //Get their "intersecting" area and check for no intersection
            ll xint = ( min((--ax.end())->first, (--bx.end())->first) - max(ax.begin()->first, bx.begin()->first) );
            ll yint = ( min((--ay.end())->first, (--by.end())->first) - max(ay.begin()->first, by.begin()->first) );
            if(xint >= 0 && yint >= 0)
                continue;
            
            //Otherwise we need to find the area of both squares
            ll areaA = ((--ax.end())->first - ax.begin()->first) * ((--ay.end())->first - ay.begin()->first);
            ll areaB = ((--bx.end())->first - bx.begin()->first) * ((--by.end())->first - by.begin()->first);
            usingTwo = min(usingTwo, areaA + areaB);
        }
    };
    solve();
    sort(v.begin(), v.end(), [&](array<ll, 2> a, array<ll, 2> b){
            return a[1] < b[1];
    });
    solve();
    cout<<single - usingTwo<<"\n";
}
