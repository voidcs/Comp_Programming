#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        set<int> s;
        for(int i = 0; i < n; i++){
            int x;
            cin>>x;
            s.insert(x);
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            int x;
            cin>>x;
            if(s.count(x))
                ans++;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}