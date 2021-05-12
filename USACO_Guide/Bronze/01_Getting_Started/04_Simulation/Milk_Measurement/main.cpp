#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const ll INF = 1e18;

struct Log{
    int t, dx;
    string name;
    bool operator < (const Log &a){
        return t < a.t;
    }
};

int main(){
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int n;
    char c;
    cin>>n;
    vector<Log> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i].t>>v[i].name>>c>>v[i].dx;
        if(c == '-')
            v[i].dx *= -1;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    map<string, int> m;
    m["Bessie"] = 7, m["Elsie"] = 7, m["Mildred"] = 7;
    set<string> s;
    for(int i = 0; i < n; i++){
        m[v[i].name] += v[i].dx;
        int hi = -1e9;
        for(auto x: m)
            hi = max(hi, x.second);
        set<string> t;
        for(auto x: m){
            if(x.second == hi)
                t.insert(x.first);
        }
        if(t != s){
            ans++;
        }
        s = t;
    }
    cout<<ans<<endl;
    
    return 0;
}