#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int> v(2*n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
        v[i+n] = v[i];
    }
    int ans = 0, cnt = 0;
    for(int i = 0; i < 2*n; i++){
        if(v[i])
            cnt++;
        else
            cnt = 0;
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;
    return 0; 
} 