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
    array<int, 2> road[n];
    for(int i = 0; i < n; i++){
        cin>>road[i][0]>>road[i][1];
        if(i)
            road[i][0] += road[i-1][0];
    }
    int pos = 0, j = 0, ans = 0;
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        pos += a;
        ans = max(ans, b - road[j][1]);
        while(j < n-1 && pos >= road[j][0]){
            ans = max(ans, b - road[j][1]);
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}