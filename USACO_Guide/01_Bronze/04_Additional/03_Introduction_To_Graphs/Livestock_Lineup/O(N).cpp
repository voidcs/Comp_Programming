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
        if(!used[i] && adj[i].size() <= 1){
            int j = i;
            while(adj[j].size() == 1){
                ans.push_back(j);
                used[j] = 1;
                int next = *adj[j].begin();
                adj[next].erase(j);
                j = next;
            }
            ans.push_back(j);
            used[j] = 1;
        }

    }
    for(auto x: ans)
        cout<<cows[x]<<endl;
    return 0;
}
