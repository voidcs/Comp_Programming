#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int n = s.length();
    unordered_set<string> all;
    for(int i = 0; i < 100; i+=4){
        string x = to_string(i);
        if(x.length() == 1)
            x = '0' + x;
        all.insert(x);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '4' || s[i] == '8' || s[i] == '0')
            ans++;
        for(auto x: all){
            if(i + (int)x.length() <= n){
                string t = s.substr(i, x.length());
                if(t == x){
                    ans += i+1;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
