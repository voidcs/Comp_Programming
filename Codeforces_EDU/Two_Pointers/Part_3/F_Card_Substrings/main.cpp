#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
    cin>>n>>m;
    string s, cards;
    cin>>s>>cards;
    map<char, int> have, used;
    for(auto x: cards)
        have[x]++;
    ll ans = 0, l = 0;
    for(int r = 0; r < n; r++){
        used[s[r]]++;
        while(used[s[r]] > have[s[r]]){
            used[s[l++]]--;
        }
        ans += r - l + 1;
    }
    cout<<ans<<endl;
    return 0;
}
