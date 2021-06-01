#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    int n;
    cin>>n;
    vector<array<int, 2>> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i][0]>>v[i][1];
    }
    vector<int> c(n, n);
    int ans = 0;
    function<void(int)> gen = [&](int paired){
        if(paired == n){
            bool ok = 0;
            for(int start = 0; start < n; start++){
                vector<bool> vis(n, 0);
                function<void(int)> dfs = [&](int u){
                    if(vis[u]){
                        ok = 1;
                        return;
                    }      
                    vis[u] = 1;
                    int closest = 2e9, to = -1;
                    for(int i = 0; i < n; i++){
                        if(v[i][1] == v[u][1] && v[i][0] > v[u][0]){
                            if(v[i][0] < closest){
                                closest = v[i][0];
                                to = i;
                            }
                        }
                    }
                    if(to == -1)
                        return;
                    dfs(c[to]);
                };
                dfs(start);
            }
            if(ok){
                ans++;
            }
            return;
        }
        int i = 0;
        for(; i < n; i++){
            if(c[i] == n)
                break;
        }
        for(int j = i+1; j < n; j++){
            if(c[j] == n){
                c[i] = j;
                c[j] = i;
                gen(paired + 2);
                c[i] = c[j] = n;
            }
        }
    };
    gen(0);
    cout<<ans<<endl;
    
    return 0;
}