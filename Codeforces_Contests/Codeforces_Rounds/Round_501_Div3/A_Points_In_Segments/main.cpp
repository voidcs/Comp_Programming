#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> vis(m+1);
    for(int i = 0; i < n; i++){
        int l, r;
        cin>>l>>r;
        for(int j = l; j <= r; j++){
            vis[j] = 1;
        }
    }
    vector<int> ans;
    for(int i = 1; i <= m; i++)
        if(!vis[i])
            ans.push_back(i);
    cout<<ans.size()<<endl;
    for(auto x: ans)
        cout<<x<<" ";
    cout<<endl;

    return 0;
}
