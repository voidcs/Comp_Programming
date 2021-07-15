#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    ll n, k;
    cin>>n>>k;
    while(k--){
        ll x;
        cin>>x;
        ll speed = 1, upDist = 0, downDist = 0, ans = 0;
        while(1){
            upDist += speed;
            ans++;
            if(upDist + downDist >= n)
                break;
            if(speed >= x){
                downDist += speed;
                ans++;
                if(upDist + downDist >= n)
                    break;
            }
            speed++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
