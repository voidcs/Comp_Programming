#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    ll n;
    cin>>n;
    vector<array<ll, 3>> v;
    vector<ll> alone(n);
    for(int i = 0; i < n; i++){
        ll a, b;
        cin>>a>>b;
        v.push_back({a, i, 1});
        v.push_back({b, i, 0});
    }
    sort(v.begin(), v.end());
    set<ll> working;
    ll currTime = 0, prevTime = 0, totalTime = 0;
    for(auto x: v){
        currTime = x[0];
        if(working.size() > 0)
            totalTime += currTime - prevTime;
        if(working.size() == 1)
            alone[*working.begin()] += currTime - prevTime;
        if(x[2])
            working.insert(x[1]);
        else
            working.erase(x[1]);
        prevTime = currTime;
    }
	
    ll minAlone = INF;
    for(int i = 0; i < n; i++)
        minAlone = min(minAlone, alone[i]);
    cout<<totalTime - minAlone<<endl;
    return 0;
}
