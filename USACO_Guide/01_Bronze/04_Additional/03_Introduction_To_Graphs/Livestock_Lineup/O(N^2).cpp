#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    map<string, int> m;
    sort(cows.begin(), cows.end());
    vector<set<int>> adj(8);
    vector<int> used(8);
    for(int i = 0; i < cows.size(); i++){
        m[cows[i]] = i;
    }
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        string a, b, t;
        cin>>a>>t>>t>>t>>t>>b;
        adj[m[a]].insert(m[b]);
        adj[m[b]].insert(m[a]);
    }
    vector<int> ans;
    for(int i = 0; i < 8; i++){
        if(adj[i].size() <= 1){
            used[i] = 1;
            ans.push_back(i);
            break;
        }
    }
    while(ans.size() != 8){
        bool mustGoAfter = 0;
        for(int i = 0; i < 8; i++){
            if(!used[i] && adj[i].count(ans.back())){
                mustGoAfter = 1;
                ans.push_back(i);
                used[i] = 1;
                break;
            }
        }
        if(!mustGoAfter){
            for(int i = 0; i < 8; i++){
                if(!used[i] && adj[i].size() < 2){
                    ans.push_back(i);
                    used[i] = 1;
                    break;
                }
            }
        }
    }
    for(auto x: ans)
        cout<<cows[x]<<endl;
    return 0;
}
