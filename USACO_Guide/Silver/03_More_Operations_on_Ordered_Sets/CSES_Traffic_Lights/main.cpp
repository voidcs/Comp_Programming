#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int x, n;
    cin>>x>>n;
    map<int, int> m;
    m[x]++;
    set<int> s;
    s.insert(0);
    s.insert(x);
    while(n--){
        cin>>x;
        auto r = s.lower_bound(x);
        auto l = --s.lower_bound(x);
        int d = *r - *l;
        m[d]--;
        if(m[d] == 0)
            m.erase(d);
        m[*r-x]++;
        m[x-*l]++;
        cout<<(*--m.end()).first<<" ";
        s.insert(x);
    }
    return 0;
}
