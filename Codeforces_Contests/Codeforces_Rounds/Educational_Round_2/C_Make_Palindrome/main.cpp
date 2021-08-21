#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    map<char, int> m;
    string s;
    cin>>s;
    for(char c: s)
        m[c]++;
    vector<char> odds;
    for(auto x: m){
        if(x.second%2){
            odds.push_back(x.first);
        }
    }
    int n = odds.size();
    if(n > 1){
        int l = 0, r = n-1;
        while(l < r){
            m[odds[l]]++;
            m[odds[r]]--;
            if(m[odds[r]] == 0)
                m.erase(odds[r]);
            l++, r--;
        }
    }
    char middle;
    int middleCnt = -1;
    for(auto x: m){
        if(x.second%2){
            middle = x.first;
            middleCnt = x.second;
        }
    }
    string ans, half;
    for(auto x: m){
        half += string(x.second/2, x.first);
    }
    ans = half;
    if(middleCnt != -1)
        ans += middle;
    reverse(half.begin(), half.end());
    ans += half;
    cout<<ans<<endl;
    return 0;
}
