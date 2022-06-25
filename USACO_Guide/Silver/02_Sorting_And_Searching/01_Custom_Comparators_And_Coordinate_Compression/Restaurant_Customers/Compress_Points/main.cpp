#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

int main(){
    int n;
    cin>>n;
    vector<array<int, 2>> v(n);
    set<int> s;
    for(auto &x: v){
        cin>>x[0]>>x[1];
        s.insert(x[0]);
        s.insert(x[1]);
    }
    int cnt = 0;
    map<int, int> compress;
    for(auto x: s){
        compress[x] = cnt++;
    }
    for(auto &x: v){
        x[0] = compress[x[0]];
        x[1] = compress[x[1]];
    }
    vector<int> p(cnt+1);
    for(auto x: v){
        p[x[0]]++, p[x[1]+1]--;
    }
    int ans = 0, sum = 0;
    for(int i = 0; i <= cnt; i++){
        sum += p[i];
        ans = max(ans, sum);
    }
    cout<<ans<<"\n";
}
