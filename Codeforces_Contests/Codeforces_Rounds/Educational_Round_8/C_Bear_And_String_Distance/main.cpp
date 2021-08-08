#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<array<int, 3>> v;
    for(int i = 0; i < n; i++){
        int x = min(s[i] - 'a', 25 - (s[i] - 'a'));
        v.push_back({x, i, s[i] - 'a'});
    }
    sort(v.begin(), v.end());
    int j = 0;
    vector<char> ans(n, '!');
    while(k){
        int x = min(k, 25 - v[j][0]);
        k -= x;
        char c;
        if(v[j][2] + x > 25)
            c = (char)((v[j][2] - x) + 'a');
        else
            c = (char)(v[j][2] + x + 'a');

        ans[v[j][1]] = c;
        j++;
        if(j == n)
            break;
    }
    for(int i = 0; i < n; i++){
        if(ans[i] == '!')
            ans[i] = s[i];
    }
    if(k > 0){
        cout<<"-1\n";
        return 0;
    }
    for(auto x: ans)
        cout<<x;
    return 0;
}
