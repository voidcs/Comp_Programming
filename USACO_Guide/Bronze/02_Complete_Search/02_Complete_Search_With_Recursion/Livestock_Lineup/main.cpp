#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout); 
    vector<string> cows = {"Beatrice", "Sue", "Belinda", "Bessie", "Betsy", 
        "Blue", "Bella", "Buttercup"};
    sort(cows.begin(), cows.end());
    int n;
    cin>>n;
    map<string, vector<string>> beside;
    for(int i = 0; i < n; i++){
        string a, b, t;
        cin>>a>>t>>t>>t>>t>>b;
        beside[a].push_back(b);
        beside[b].push_back(a);
    }
    vector<string> ans;
    vector<string> v;
    map<string, int> used, index;
    function<void()> create = [&](){
        if(v.size() == 8){
            bool valid = 1;
            for(auto x: beside){
                for(auto y: x.second){
                    if(abs(index[x.first] - index[y]) > 1)
                        valid = 0;
                }
            }
            if(!valid)
                return;
            if(ans.empty())
                ans = v;
            else
                ans = min(ans, v);
            return;
        }
        for(int i = 0; i < 8; i++){
            if(used[cows[i]] == 0){
                used[cows[i]] = 1;
                v.push_back(cows[i]);
                index[cows[i]] = v.size();
                create();
                used[cows[i]] = 0;
                v.pop_back();
            }
        }
    };
    create();
    for(auto x: ans)
        cout<<x<<endl;
    
    return 0;
}