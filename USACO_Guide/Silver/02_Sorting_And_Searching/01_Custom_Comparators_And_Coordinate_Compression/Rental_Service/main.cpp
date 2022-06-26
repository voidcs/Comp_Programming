#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    ll n, m, r;
    cin>>n>>m>>r;
    vector<ll> cows(n), rent(r), milkPrefix(n+1);
    vector<array<ll, 2>> sell(m);
    for(auto &x: cows)
        cin>>x;
    for(auto &x: sell)
        cin>>x[0]>>x[1];
    for(auto &x: rent)
        cin>>x;
    sort(cows.rbegin(), cows.rend());
    sort(rent.rbegin(), rent.rend());
    for(ll i = 0; i < n; i++){
        milkPrefix[i+1] = milkPrefix[i] + cows[i];
    }
    auto comp = [&](array<ll, 2> lhs, array<ll, 2> rhs){
        return lhs[1] > rhs[1];
    };
    sort(sell.begin(), sell.end(), comp);
    map<ll, array<ll, 2>> p;
    p[0] = {0, -1};
    ll gallons = 0, sum = 0;
    ll saveIndex = 0;
    for(auto x: sell){
        gallons += x[0], sum += x[0] * x[1];
        p[gallons] = {sum, saveIndex};
        saveIndex++;
    }
    sell.push_back({0, 0});
    //Try selling 0 to r cows
    //Use pref sum to check in log(n) how much money we can make by selling
    ll ans = 0;
    ll profitRent = 0;
    for(ll rentCnt = 0; rentCnt <= r; rentCnt++){
		//Make sure to not profit from more customers than we have cows!!!!!
		//I was stuck on this for hours
        if(rentCnt && rentCnt <= n)
            profitRent += rent[rentCnt-1];
        ll produce = milkPrefix[max(0LL, n-rentCnt)];
        auto it = p.upper_bound(produce);
        it--;
        ll i = it->second[1];
        ll soldProfit = it->second[0] + (max(0LL, produce - it->first) * sell[i+1][1]);
        ans = max(ans, soldProfit + profitRent);
    }
    cout<<ans<<"\n";
    return 0;
}
