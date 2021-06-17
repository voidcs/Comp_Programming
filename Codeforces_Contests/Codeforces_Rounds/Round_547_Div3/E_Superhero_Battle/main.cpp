#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll h, n;
    cin>>h>>n;
    vector<ll> v(n);
    ll cycle = 0; //Amount that we will lower the boss's health with each loop
    ll x = INF; //Biggest amount we can remove in a single round
    for(ll &x: v)
        cin>>x;
    for(int i = 0; i < n; i++){
        cycle += v[i];
        x = min(x, cycle);
    }
    //If we can't beat it in one round and we never get his hp lower in an iteration, it's impossible
    if(cycle >= 0 && h + x > 0){
        cout<<"-1\n";
        return 0;
    }
    ll ans = 0;
    //Deduce his hp to state where we can win in just one more loop
    if(cycle < 0){
        ll loops = ((h + x - cycle - 1) / -cycle);
        ans += n * loops;
        h -= (loops * -cycle);
        ans = max(ans, 0LL);
    }
    //At this point eventually we will defeat him in one iteration
    for(int i = 0; i < n; i++){
        if(h <= 0)
            break;
        h += v[i];
        ans++;
    }
    cout<<ans<<endl;
    return 0; 
} 