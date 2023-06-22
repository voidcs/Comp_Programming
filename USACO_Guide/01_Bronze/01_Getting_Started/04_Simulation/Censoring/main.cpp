#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
    string s, t;
    cin>>s>>t;
    int n = s.length(), m = t.length();
    string ans;
    for(int i = 0; i < n; i++){
        ans += s[i];
        if(ans.length() >= m && ans.substr(ans.length() - m,m) == t){
            ans.resize(ans.size() - t.size());
        }
    }
    cout<<ans<<endl;

    return 0;
}