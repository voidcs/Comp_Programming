#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e10;

//PROBLEM LINK
//https://codeforces.com/contest/888/problem/E

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, x;
    cin>>n>>m;
    vector<ll> a, b;

    for(int i = 0; i < n/2; i++){
        cin>>x;
        a.push_back(x);
    }
    for(int i = n/2; i < n; i++){
        cin>>x;
        b.push_back(x);
    }
    
    set<ll> used;
    vector<ll> sums;
    for(int i = 0; i < 1<<(ll)a.size(); i++){
        ll sum = 0;
        for(int j = 0; j < a.size(); j++){
            if(i&1<<j)
                sum += a[j];
        }
        sum %= m;
        if(!used.count(sum))
            sums.push_back(sum);   
        used.insert(sum);
    }

    sort(sums.begin(), sums.end());
    ll ans = 0;
    for(int i = 0; i < 1<<(ll)b.size(); i++){
        ll sum = 0;
        for(int j = 0; j < b.size(); j++){
            if(i&1<<j)
                sum += b[j];
        }
        sum %= m;
        ll index = lower_bound(sums.begin(), sums.end(), (m-sum)) - sums.begin();
        index--;
        if(index < 0)
            continue;
        ll z = sums[index];
        ans = max(ans, (sum+z) % m);
    }
    cout<<ans<<endl;
    return 0;
    
}