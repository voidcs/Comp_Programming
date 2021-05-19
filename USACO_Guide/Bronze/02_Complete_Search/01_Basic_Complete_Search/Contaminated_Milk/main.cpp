#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    //Notes: we do not know exactly which is the bad milk
    //but we can narrow it down to all the milks that people who became sick drank
    //take the milk that the most people drank (even if they are not told to be sick)
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);
    int n, m, d, s;
    cin>>n>>m>>d>>s;
    vector<array<int, 3>> v(d);
    for(int i = 0; i < d; i++)
        for(int j = 0; j < 3; j++)
            cin>>v[i][j];
    vector<array<int, 2>> sick(s);
    for(int i = 0; i < s; i++){
        cin>>sick[i][0]>>sick[i][1]; 
    }
    //if a sick person drank this milk prior to becoming sick, increase the freq of the milk number
    map<int, int> freq;
    for(int i = 0; i < s; i++){
        for(int j = 0; j < d; j++){
            if(v[j][0] == sick[i][0] && v[j][2] < sick[i][1]){
                freq[v[j][1]]++;
            }
        }
    }
    //all milks that sick people drank before becoming sick will be candidates if they have the highest frequency
    int best = -1;
    for(auto x: freq)
        best = max(best, x.second);
    set<int> bad;
    for(auto x: freq){
        if(x.second == best)
            bad.insert(x.first);
    }
    //For each potential bad milk, add each person that drank it
    map<int, set<int>> ans;
    for(int i = 0; i < d; i++){
        if(bad.count(v[i][1]))
            ans[v[i][1]].insert(v[i][0]);
    }
    //Answer is the milk that could have made the most people sick if it was the bad one
    int buy = 0;
    for(auto x: ans)
        buy = max(buy, (int)x.second.size());
    cout<<buy<<endl;

    return 0;
}
