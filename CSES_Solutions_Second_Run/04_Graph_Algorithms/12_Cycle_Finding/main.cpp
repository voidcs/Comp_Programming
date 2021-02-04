#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n, m;
    cin>>n>>m;
    vector<vector<array<ll, 2>>> adj(n+1);
    //Initialize everything to zero to account for multiple connected components
    vector<ll> dist(n+1, 0), last(n+1, -1);
    while(m--){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({c, b});
    }

    ll x = 0;
    for(int i = 0; i < n; i++){
        x = 0;
        for(int j = 1; j <= n; j++){
            for(array<ll, 2> a: adj[j]){
                ll d = a[0];
                ll c = a[1];
                if(d + dist[j] < dist[c]){
                    dist[c] = d + dist[j];
                    last[c] = j;
                    x = c;
                }
            }
        }
    }
    if(x == 0){
        cout<<"NO\n";
        return 0;
    }
    //It is possible that x is not actually in the cycle and that
    //x was minimized after the cycle was done, so we backtrack n-1 times
    //to guarantee we are at the start of a cycle
    for(int i = 0; i < n-1; i++)
        x = last[x];
    
    vector<ll> cycle;
    ll curr = last[x];
    cycle.push_back(x);
    while(curr != x){
        cycle.push_back(curr);
        curr = last[curr];
    }
    cycle.push_back(x);

    reverse(cycle.begin(), cycle.end());
    cout<<"YES\n";
    for(auto x: cycle)
        cout<<x<<" ";
    cout<<endl;
    
    return 0;
}