#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> v(n);
    vector<string> order(n);
    for(int &x: v)
        cin>>x;
    for(auto &x: order)
        cin>>x;
    for(int i = 0; i < 3; i++){
        vector<string> t(n);
        for(int j = 0; j < n; j++){
            t[j] = order[v[j]-1];
        }
        order = t;
    }
    for(auto x: order)
        cout<<x<<endl;
    
    return 0;
}