#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    ll ans = 0;
    queue<int> q;
    set<int> s;
    for(int i = 0; i < n; i++){
        while(s.count(a[i])){
            s.erase(q.front());
            q.pop();
        }
        q.push(a[i]);
        s.insert(a[i]);
        ans = max(ans, (ll)q.size());
    }
    cout<<ans<<endl;
    return 0;
}