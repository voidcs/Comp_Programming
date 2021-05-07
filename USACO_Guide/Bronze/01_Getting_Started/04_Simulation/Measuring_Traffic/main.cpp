#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int n;
    cin>>n;
    vector<string> type(n);
    vector<array<int, 2>> v(n);
    for(int i = 0; i < n; i++)
        cin>>type[i]>>v[i][0]>>v[i][1];
    int l = 0, r = 1e9;
    for(int i = n-1; ~i; i--){
        if(type[i] == "on"){
            l -= v[i][1];
            r -= v[i][0];
            l = max(l, 0);
        }
        if(type[i] == "none")
            l = max(l, v[i][0]), r = min(r, v[i][1]);
        if(type[i] == "off")
            l += v[i][0], r += v[i][1];
    }
    cout<<l<<" "<<r<<endl;
    
    l = 0, r = 1e9;
    for(int i = 0; i < n; i++){
        if(type[i] == "on")
            l += v[i][0], r += v[i][1];
        if(type[i] == "none")
            l = max(l, v[i][0]), r = min(r, v[i][1]);
        if(type[i] == "off"){
            l -= v[i][1];
            r -= v[i][0];
            l = max(l, 0);
        }
    }
    cout<<l<<" "<<r<<endl;
    return 0;
}