#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    map<int, int> m;
    for(int &x: v){
        cin>>x;
        m[x]++;
    }
    int l = 1, r = n;
    vector<int> ans, g;
    auto valid = [&](int copies){
        g.clear();
        for(auto x: m){
            for(int i = 0; i < x.second/copies; i++)
                g.push_back(x.first);
        }
        return g.size() >= k;
    };
    while(l <= r){
        int m = (l+r) / 2;
        if(valid(m)){
            ans = g;
            l = m+1;
        }
        else
            r = m-1;
    }
    for(int i = 0; i < k; i++)
        cout<<ans[i]<<" ";
    return 0;
}
