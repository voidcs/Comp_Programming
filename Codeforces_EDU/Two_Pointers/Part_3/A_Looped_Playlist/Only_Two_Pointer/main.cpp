#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, p;
    cin>>n>>p;
    vector<ll> v(n);
    ll cycle = 0;
    for(ll &x: v){
        cin>>x;
        cycle += x;
    }
    for(int i = 0; i < n; i++)
        v.push_back(v[i]);
    ll ans = INF, index = 0;
    if(cycle == p){
        cout<<"1 "<<n<<endl;
    }
    else{
        ll x = p/cycle;
        p -= x * cycle;
        ll l = 0, sum = 0;
        for(int r = 0; r < n*2; r++){
            sum += v[r];
            while(l < 2*n && sum - v[l] >= p)
                sum -= v[l++];
            if(sum >= p){
                if(r-l+1 < ans){
                    ans = r-l+1;
                    index = r - ans + 1;
                    if(index >= n)
                        index -= n;
                }
            }
        }
        cout<<index+1<<" "<<ans + (x*n)<<endl;
    }
    return 0;
}
