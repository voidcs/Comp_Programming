#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    string s;
    cin>>s;
    ll n = s.length();
    ll ans = 0, cnt = 0;
    for(int i = 0; i < n;){
        char c = s[i];
        cnt = 0;
        while(i < n && s[i] == c){
            cnt++;
            i++;
        }
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;
    return 0;
}
