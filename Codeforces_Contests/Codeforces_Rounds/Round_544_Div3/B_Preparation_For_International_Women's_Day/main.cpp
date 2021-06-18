#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n, k;
    cin>>n>>k;
    map<int, int> m;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int need = k - (v[i] % k);
        int have = v[i] % k;
        need %= k;
        m[have]++;
        if(need == have){
            if(m[need] >= 2){
                ans += 2;
                m[need] -= 2;
            }
        }
        else if(m[need] && m[have]){
            ans += 2;
            m[need]--;
            m[have]--;
        }
    }
    cout<<ans<<endl;
    return 0;
}