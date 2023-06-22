#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("notlast.in", "r", stdin);
    //freopen("notlast.out", "w", stdout);
    int n;
    cin>>n;
    vector<string> cows = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    map<string, int> m;
    for(auto x: cows)
        m[x] = 0;
    for(int i = 0; i < n; i++){
        string s;
        int x;
        cin>>s>>x;
        m[s] += x;
    }
    map<int, int> freq;
    map<int, string> ans;
    for(auto x: m){
        freq[x.second]++;
        ans[x.second] = x.first;
    }
    freq.erase(freq.begin());
    
    if(freq.begin()->second == 1)
        cout<<ans[freq.begin()->first]<<endl;
    else
        cout<<"Tie\n";
    
    return 0;
}