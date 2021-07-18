#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    //freopen("hps.in", "r", stdin);
    //freopen("hps.out", "w", stdout);
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<char, vector<int>> m;
    for(int i = n-1; i >= 0; i--){
        m[s[i]].push_back(i);
    }
    set<int> ignore;
    for(int i = 0; i < k; i++){
        bool found = 0;
        for(char c = 'a'; c <= 'z'; c++){
            if(m[c].size() > 0){
                ignore.insert(m[c].back());
                m[c].pop_back();
                found = 1;
                break;
            }
        }
    }
    string ans;
    for(int i = 0; i < n; i++){
        if(!ignore.count(i))
            ans += s[i];
    }
    cout<<ans<<endl;
    return 0;
}
