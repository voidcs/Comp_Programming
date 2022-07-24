#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(x >= v[i]){
            ans++;
            x -= v[i];
        }
    }
    cout<<ans<<"\n";
}
