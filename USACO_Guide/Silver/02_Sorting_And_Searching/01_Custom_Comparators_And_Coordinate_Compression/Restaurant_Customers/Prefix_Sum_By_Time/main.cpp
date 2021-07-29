#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    int n;
    cin>>n;
    vector<array<int, 2>> v(n), order;
    for(int i = 0; i < n; i++){
        cin>>v[i][0]>>v[i][1];
        order.push_back({v[i][0], 1});
        order.push_back({v[i][1], -1});
    }
    sort(order.begin(), order.end());
    int ans = 0, sum = 0;
    for(auto x: order){
        sum += x[1];
        ans = max(ans, sum);
    }
    cout<<ans<<endl;
    return 0;
}
