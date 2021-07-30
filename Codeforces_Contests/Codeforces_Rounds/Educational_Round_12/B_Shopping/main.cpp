#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<int> items(k);
    for(int &x: items)
        cin>>x;
    vector<vector<int>> v(n, vector<int>(m));
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>v[i][j];
            auto it = find(items.begin(), items.end(), v[i][j]);
            ans += (it-items.begin()) + 1;
            items.erase(it);
            items.insert(items.begin(), v[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
