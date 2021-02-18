#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n), vis(n, 0), depth(n, 0);
        array<int, 2> u = {-1, -1};
        for(int i = 0; i < n; i++){
            cin>>a[i];
            if(a[i] > u[0]){
                u[0] = a[i];
                u[1] = i;
            }
        }
        function<void(int, int)> dfs = [&](int u, int d){
            vis[u] = 1;
            depth[u] = d;
            array<int, 2> left = {-1, -1}, right = {-1, -1};
            for(int i = u-1; i >= 0; i--){
                if(vis[i])
                    break;
                if(a[i] > left[0]){
                    left[0] = a[i];
                    left[1] = i;
                }
            }
            if(left[0] != -1)
                dfs(left[1], d+1);
            
            for(int i = u+1; i < n; i++){
                if(vis[i])
                    break;
                if(a[i] > right[0]){
                    right[0] = a[i];
                    right[1] = i;
                }
            }
            if(right[0] != -1)
                dfs(right[1], d+1);
        };
        
        dfs(u[1], 0);
        for(int i = 0; i < n; i++)
            cout<<depth[i]<<" ";
        cout<<endl;
    }
    return 0;
}