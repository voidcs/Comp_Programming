#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    map<ll, set<ll>> m;
    int k;
    cin>>k;
    vector<vector<ll>> v(k+1);
    vector<ll> sums(k+1);
    for(int i = 1; i <= k; i++){
        ll n;
        cin>>n;
        v[i] = vector<ll>(n);
        ll sum = 0;
        for(ll &x: v[i]){
            cin>>x;
            sum += x;
        }
        sums[i] = sum;
        for(auto x: v[i]){
            m[sum-x].insert(i);
        }
    }
    for(auto x: m){
        if(x.second.size() >= 2){
            ll sum = x.first;
            ll a = *x.second.begin();
            ll b = *(++x.second.begin());
            cout<<"YES\n";
            cout<<a<<" ";
            for(int i = 0; i < v[a].size(); i++){
                if(sums[a] - v[a][i] == sum){
                    cout<<i+1<<endl;
                    break;
                }
            }
            cout<<b<<" ";
            for(int i = 0; i < v[b].size(); i++){
                if(sums[b] - v[b][i] == sum){
                    cout<<i+1<<endl;
                    break;
                }
            }
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}
