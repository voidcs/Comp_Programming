#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        ll bottom[n], left[m];
        set<int> s;
        for(int i = 0; i < n; i++){
            cin>>bottom[i];
            s.insert(bottom[i]);
        }
        ll ans = 0;
        for(int i = 0; i < m; i++){
            cin>>left[i];
            if(s.count(left[i]))
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}