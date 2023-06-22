#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int n, m;
    cin>>n>>m;
    int len, s;
    //Store the speed and limit at every single section of road
    vector<int> speed(100), limit(100);
    int start = 0;
    for(int i = 0; i < n; i++){
        cin>>len>>s;
        for(int i = start; i < start + len; i++)
            limit[i] = s;
        start += len;
    }
    
    start = 0;
    for(int i = 0; i < m; i++){
        cin>>len>>s;
        for(int i = start; i < start + len; i++)
            speed[i] = s;
        start += len;
    }
    int ans = 0;
    //Check difference between speed Bessie was going and the limit at that point
    for(int i = 0; i < 100; i++){
        ans = max(ans, speed[i] - limit[i]);
    }
    cout<<ans<<endl;
    
    return 0;
}