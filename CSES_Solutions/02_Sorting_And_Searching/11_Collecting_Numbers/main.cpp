#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
 
int main(){
    ll n;
    cin>>n;
    ll a[n];
    map<ll, ll> m;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        m[a[i]] = i;
    }
    ll last = -1, ans = 0;
    for(int i = 1; i <= n; i++){
        while(i <= n){
            if(m[i] < last){s
                i--;
                break;
            }
            last = m[i];
            i++;
        }
        last = -1;
        ans++;
    }
    cout<<ans<<endl;
    
    return 0;
}