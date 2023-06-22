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
        ll l = 0, r = 1e7;
        ll ans = 1e18;
        auto valid = [&](ll m){
            //Miles remaining after we reach our top speed of m
            ll r = (n - (m*(m+1))/2);
            if(m <= x){
                if(r < 0)
                    return -1LL;
                return m + max(0LL, (r+m-1)/m);
            }
            else{
                //Also include the miles spent having to go down to speed x
                ll neg = r - (((m-1) * (m)) / 2) + ((x*(x-1)) / 2);
                //If we already passed n miles by going up to speed mid and then down to x, then we try a slower speed
                if(neg < 0)
                    return -1LL;
                //Otherwise, return how many steps it took
                return m + (m - x) + ((neg + m - 1) / m);
            }
        };
        //Binary search for the top speed we should try to reach
        //If we cannot make it down to speed x before surpassing n miles then it is invalid
        //If we also exceed n miles after reaching speed mid, we must try a slower speed
        //Otherwise update and try to find better answer
        while(l <= r){
            ll mid = (l+r) / 2;
            ll res = valid(mid);
            if(res != -1){
                l = mid+1;
                ans = min(ans, res);
            }
            else
                r = mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
