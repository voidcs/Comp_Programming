#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<ll> v(n);
    ll sum = 0;
    map<ll, ll> m;
    for(ll &x: v){
        cin>>x;
        sum += x;
        m[x]++;
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        sum -= v[i];
        if(sum % 2 == 0){
            m[v[i]]--;
            if(m[sum/2])
                ans.push_back(i+1);
            m[v[i]]++;
        }
        sum += v[i];
    }
    cout<<ans.size()<<endl;
    for(int x: ans)
        cout<<x<<" ";

    return 0;
}
