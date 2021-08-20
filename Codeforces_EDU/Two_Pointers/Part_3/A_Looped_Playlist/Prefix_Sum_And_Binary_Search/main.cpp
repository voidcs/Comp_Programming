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
    else if(cycle < p){
        ll x = p/cycle;
        p -= x * cycle;
        vector<ll> pre(2*n+1);
        ll prefixSum = 0;
        for(int i = 0; i < 2*n; i++){
            prefixSum += v[i];
            pre[i+1] = prefixSum;
        }
        ll l = 0, r = n, save = 0;
        auto valid = [&](ll x){
            for(int i = 0; i < n; i++){
                if(pre[i+x] - pre[i] >= p){
                    save = i;
                    return true;
                }
            }
            return false;
        };
        while(l <= r){
            ll m = (l+r)/2;
            if(valid(m)){
                ans = m;
                index = save;
                r = m-1;
            }
            else
                l = m+1;
        }
        ans = ans + (n*x);
        if(index >= n)
            index -= n;
        cout<<index+1<<" "<<ans<<endl;
    }
    else if(cycle > p){
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
        cout<<index+1<<" "<<ans<<endl;
    }
    return 0;
}
