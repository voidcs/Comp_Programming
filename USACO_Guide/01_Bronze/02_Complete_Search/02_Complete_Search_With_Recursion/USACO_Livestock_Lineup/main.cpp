#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    //freopen("input.txt", "r", stdin);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    int n;
    cin>>n;
    map<string, vector<string>> m;
    m["Bessie"];
    m["Buttercup"];
    m["Belinda"];
    m["Beatrice"];
    m["Bella"];
    m["Blue"];
    m["Betsy"];
    m["Sue"];
    map<string, int> vis;
    for(auto x: m)
        vis[x.first] = 0;
    for(int i = 0; i < n; i++){
        string a, b, t;
        cin>>a>>t>>t>>t>>t>>b;
        m[a].push_back(b);
        m[b].push_back(a);
    }
    vector<string> ans, v;
    function<void(int)> create = [&](int t){
        if(t == 8){
            map<string, int> index;
            for(int i = 0; i < 8; i++){
                index[v[i]] = i;
            }
            bool ok = 1;
            for(auto x: m){
                for(string s: x.second){
                    if(abs(index[x.first] - index[s]) != 1)
                        ok = 0;
                }
            }
            if(!ok)
                return;
            if(!ans.size())
                ans = v;
            else
                ans = min(ans, v);
            return;
        }
        for(auto x: m){
            if(!vis[x.first]){
                vis[x.first] = 1;
                v.push_back(x.first);
                create(t+1);
                v.pop_back();
                vis[x.first] = 0;
            }
        }
    };
    create(0);
    for(auto x: ans)
        cout<<x<<endl;
    return 0;
}