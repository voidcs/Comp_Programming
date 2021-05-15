#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    string s;
    cin>>s;
    map<char, vector<int>> m;
    for(int i = 0; i < s.length(); i++){
        m[s[i]].push_back(i);
    }
    set<string> ans;
    for(auto x: m){
        map<char, int> cnt;
        int l = x.second[0], r = x.second[1];
        for(int i = l+1; i < r; i++){
            cnt[s[i]]++;
        }
        for(auto y: cnt){
            if(y.second == 1){
                char a = x.first, b = y.first;
                if(a > b)
                    swap(a, b);
                ans.insert(string(1, a) + b);
            }
        }
    }
    cout<<ans.size()<<endl;

    return 0;
}
