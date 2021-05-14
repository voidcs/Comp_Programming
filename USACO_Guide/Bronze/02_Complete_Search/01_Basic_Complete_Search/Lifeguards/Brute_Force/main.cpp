#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int n;
    cin>>n;
    vector<array<int, 2>> v(n);
    vector<int> vis(1001);
    for(int i = 0; i < n; i++){
        cin>>v[i][0]>>v[i][1];
        for(int j = v[i][0]; j < v[i][1]; j++)
            vis[j]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = v[i][0]; j < v[i][1]; j++){
            vis[j]--;
        }
        int cnt = 0;
        for(int j = 0; j <= 1000; j++){
            if(vis[j])
                cnt++;
        }
        ans = max(ans, cnt);
        for(int j = v[i][0]; j < v[i][1]; j++){
            vis[j]++;
        }
    }
    cout<<ans<<endl;

    return 0;
}
