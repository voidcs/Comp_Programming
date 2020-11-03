#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    
    set<ll> s;
    queue<ll> q;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(s.count(a[i])){
            while(!q.empty() && q.front() != a[i]){
                ll x = q.front();
                q.pop();
                s.erase(x);
            }
            s.erase(q.front());
            q.pop();
        }
        s.insert(a[i]);
        q.push(a[i]);
        ans = max(ans, (ll)s.size());
    }
    cout<<ans<<endl;
    
    return 0;
}