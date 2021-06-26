#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n, x, t;
        cin>>n>>x>>t;
        ll f = max(0LL, (n*x) - t);
        //d represents the number of people who will have the maximal value of dissatisfaction
        ll d = (f+x-1)/x;
        //For each of these d people, all n-d people behind them have started the contest at the time that these d people finish
        ll ans = d * (n-d);
        //For the remaining people, just take everyone who is behind them
        //This ends up being the summation from 1 to #of people left
        n -= d;
        n--;
        ans += (n*(n+1))/2;
        cout<<ans<<endl;
    }
    return 0;
}