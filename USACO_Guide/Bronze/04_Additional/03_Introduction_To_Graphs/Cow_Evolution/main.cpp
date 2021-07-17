#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

//The tree is invalid if there is a cow that contains only characteristic A, a cow that only contains
//characteristics B, and then a cow that contains both.
//This implies that the two characteristics are on separate sides of the tree yet there is somehow
//a cow with both

int main(){
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
    int n;
    cin>>n;
    vector<set<string>> v(n);
    set<string> features;
    for(int i = 0; i < n; i++){
        int m;
        cin>>m;
        for(int j = 0; j < m; j++){
            string s;
            cin>>s;
            v[i].insert(s);
            features.insert(s);
        }
    }
    vector<string> f;
    for(auto x: features)
        f.push_back(x);
    for(int a = 0; a < f.size(); a++){
        for(int b = a+1; b < f.size(); b++){
            bool onlyA = 0, onlyB = 0, both = 0;
            for(int i = 0; i < n; i++){
                if(v[i].count(f[a]) && v[i].count(f[b]))
                    both = 1;
                else if(v[i].count(f[a]))
                    onlyA = 1;
                else if(v[i].count(f[b]))
                    onlyB = 1;
            }
            if(onlyA && onlyB && both){
                cout<<"no\n";
                return 0;
            }
        }
    }
    cout<<"yes\n";

    return 0;
}
