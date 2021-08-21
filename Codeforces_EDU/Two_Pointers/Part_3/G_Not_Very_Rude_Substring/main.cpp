#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ll n, c;
    cin>>n>>c;
    string s;
    cin>>s;
    map<char, ll> m;
    ll l = 0, ans = 0;
    ll bal = 0;
    for(int r = 0; r < n; r++){
        m[s[r]]++;
        if(s[r] == 'b')
            bal += m['a'];
        while(l < n && bal > c){
            m[s[l]]--;
            if(s[l] == 'a')
                bal -= m['b'];
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout<<ans<<endl;
    return 0;
}
