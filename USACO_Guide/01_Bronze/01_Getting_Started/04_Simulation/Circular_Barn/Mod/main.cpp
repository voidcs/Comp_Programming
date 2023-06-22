#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        int sum = 0;
        //distance j away from desired room
        for(int j = 1; j < n; j++){
            sum += j * (v[(i+j) % n]);
        }
        ans = min(ans, sum);
    }
    cout<<ans<<endl;
    
    return 0;
}