#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    map<int, int> m, index;
    for(int i = 0; i < n; i++){
        m[v[i]] = m[v[i]-1] + 1;
    }
    int ans = -1, f = 0;
    for(auto x: m){
        if(x.second > f){
            f = x.second;
            ans = x.first;
        }
    }
    cout<<f<<endl;
    int start = ans-f+1;
    for(int i = 0; i < n; i++){
        if(v[i] == start && start <= ans){
            cout<<i+1<<" ";
            start++;
        }
    }
    return 0;
}
