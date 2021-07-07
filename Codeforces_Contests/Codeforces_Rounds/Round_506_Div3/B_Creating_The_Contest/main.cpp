#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    int ans = 1, cnt = 1;
    for(int i = 1; i < n; i++){
        if(v[i] <= v[i-1]*2)
            cnt++;
        else{
            cnt = 1;
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;
    return 0;
}
