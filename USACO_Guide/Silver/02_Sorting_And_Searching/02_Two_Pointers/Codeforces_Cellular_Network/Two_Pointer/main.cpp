//https://codeforces.com/contest/702/problem/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, m;
    cin>>n>>m;
    vector<ll> cities(n), towers(m);
    for(ll &x: cities)
        cin>>x;
    for(ll &x: towers)
        cin>>x;
    ll ans = 0, j = 0;
    for(int i = 0; i < n; i++){
        //Choose between two towers, if the right one is closer we move to it
        //Go to next one if the values are equal so that we can account for duplicate tower values
        //This lets us find a closer tower after a[j] == a[j+1]
        while(j < m-1 && abs(cities[i] - towers[j]) >= abs(cities[i] - towers[j+1]))
            j++;
        ans = max(ans, abs(cities[i] - towers[j]));
    }
    cout<<ans<<endl;
    return 0;
}
