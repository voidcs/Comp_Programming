#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int n;
    cin>>n;
    vector<array<int, 3>> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    int ans = 0;
    for(int x: {1, 2, 3}){
        int cnt = 0;
        vector<int> location(4);
        location[x] = 1;
        for(int i = 0; i < n; i++){
            swap(location[v[i][0]], location[v[i][1]]);
            if(location[v[i][2]])
                cnt++;
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;
    
    return 0;
}