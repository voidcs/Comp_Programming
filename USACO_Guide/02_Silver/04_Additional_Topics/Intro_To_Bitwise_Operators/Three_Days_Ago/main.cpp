#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;
 
int main(){
    string s;
    cin>>s;
    int n = s.length();
    vector<int> cnt(1<<10);
    cnt[0] = 1;
    int p = 0;
    ll ans = 0;
    for(char c: s){
        p ^= (1 << (c - '0'));
        ans += cnt[p];
        cnt[p]++;
    }
    cout<<ans<<"\n";
}
