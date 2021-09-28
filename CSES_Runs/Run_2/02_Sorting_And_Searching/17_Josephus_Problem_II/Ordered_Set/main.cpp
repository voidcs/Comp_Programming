#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds; 
using namespace std;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;
 
int main(){
    ll n, k;
    cin>>n>>k;
    oset <ll> s;
    for(int i = 1; i <= n; i++)
        s.insert(i);
    ll i = k % n;
    while(s.size() > 1){
        ll x = *s.find_by_order(i);
        cout<<x<<" ";
        s.erase(x);
        i = (i+k) % (ll)s.size();
    }
    cout<<*s.begin()<<endl;
    return 0;
}