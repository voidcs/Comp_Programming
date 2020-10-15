#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//PROBLEM LINK
//https://codeforces.com/problemset/problem/550/B

int main(){
    ll n, l, r, x;
    cin>>n>>l>>r>>x;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    
    ll ans = 0;
    for(int i = 0; i < (1<<n); i++){
        vector<int> v;
        for(int j = 0; j < n; j++){
            ll f = (1<<j);
            if(i&f)
                v.push_back(a[j]);
        }
        if(v.size() >= 2){
            ll sum = 0;
            for(auto x: v)
                sum += x;
            
            sort(v.begin(), v.end());
            if(sum <= r && sum >= l){
                if(abs(v[v.size()-1] - v[0]) >= x)
                    ans++;
            }
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}