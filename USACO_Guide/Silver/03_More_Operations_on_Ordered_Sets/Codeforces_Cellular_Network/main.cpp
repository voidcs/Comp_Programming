//https://codeforces.com/contest/702/problem/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> cities(n), towers(m);
    set<int> s;
    for(int i = 0; i < n; i++)
        cin>>cities[i];
    for(int i = 0; i < m; i++){
        cin>>towers[i];
        s.insert(towers[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        auto it = s.lower_bound(cities[i]);
        if(it == s.end())
            it--;
        int dist = abs(cities[i] - *it);
        if(it != s.begin()){
            it--;
            dist = min(dist, abs(cities[i] - *it));
        }
        ans = max(ans, dist);
    }
    cout<<ans<<endl;
    return 0;
}
