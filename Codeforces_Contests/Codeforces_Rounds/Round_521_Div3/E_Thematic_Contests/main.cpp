#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    //freopen("input.txt", "r", stdin);
    ll n;
    cin>>n;
    vector<ll> v(n);
    multiset<ll> s;
    map<ll, ll> m;
    for(ll &x: v){
        cin>>x;
        m[x]++;
    }
    for(auto x: m){
        //cout<<x.second<<" ";
        s.insert(x.second);
    }
    //cout<<endl;
    
    ll ans = 0;
    for(int i = 1; i <= 200005; i++){
        if(*(--s.end()) < i)
            break;
        vector<ll> used;
        ll sum = 0, cnt = i;
        while(1){
            if(s.lower_bound(cnt) != s.end()){
                used.push_back(*s.lower_bound(cnt));
                s.erase(s.lower_bound(cnt));
                sum += cnt;
                cnt *= 2;
            }
            else
                break;
        }
        for(auto x: used){
            s.insert(x);
        }
        ans = max(ans, sum);
    }
    cout<<ans<<endl;
    
    return 0;
}