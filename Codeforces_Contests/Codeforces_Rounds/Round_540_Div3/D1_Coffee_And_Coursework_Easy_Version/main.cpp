#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    for(int &x: v){
        cin>>x;
    }
    sort(v.rbegin(), v.rend());
    int ans = 1e9;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 0; j < n; j++){
            sum += max(0, v[j] - j/i);
        }
        if(sum >= k)
            ans = min(ans, i);
    }
    if(ans == 1e9)
        cout<<"-1\n";
    else
        cout<<ans<<endl;
    
    return 0;
}
