#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    vector<string> ans;
    map<char, int> m;
    for(char c: s)
        m[c]++;
    function<void(string)> create = [&](string t){
        if(t.length() == s.length()){
            ans.push_back(t);
            return;
        }
        for(char c = 'a'; c <= 'z'; c++){
            if(m[c] > 0){
                m[c]--;
                create(t + c);
                m[c]++;
            }
        }
    };
    create("");
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto x: ans)
        cout<<x<<endl;
    return 0;
}