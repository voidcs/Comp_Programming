#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> v(n);
    for(int &x: v)
        cin>>x;
    map<int, int> m;
    for(int i = 0; i < n; i++){
        int need = x - v[i];
        if(m.count(need)){
            cout<<m[need]<<" "<<i+1<<endl;
            return 0;
        }
        m[v[i]] = i+1;
    }
    cout<<"IMPOSSIBLE\n";
    
    return 0;
}