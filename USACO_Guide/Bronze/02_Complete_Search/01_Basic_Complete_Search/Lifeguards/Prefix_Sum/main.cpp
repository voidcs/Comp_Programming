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
    vector<int> vis(1001), solo(1001);
    for(int i = 0; i < n; i++){
        cin>>v[i][0]>>v[i][1];
        vis[v[i][0]]++, vis[v[i][1]]--;
    }
    int sum = 0, have = 0;
    for(int i = 0; i <= 1000; i++){
        sum += vis[i];
        if(sum){
            have++;
            if(sum == 1)
                solo[i] = 1;
        }
    }
    vector<int> prefix(1002);
    sum = 0;
    for(int i = 1; i <= 1001; i++){
        sum += solo[i-1];
        prefix[i] = sum;
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int l = v[i][0], r = v[i][1];
        int remove = prefix[r] - prefix[l];
        ans = max(ans, have - remove);
    }
    cout<<ans<<endl;

    return 0;
}
