#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n;
    cin>>n;
    vector<char> v(n);
    vector<char> c = {'H', 'P', 'S'};
    map<char, vector<int>> p;
    for(auto x: c)
        p[x] = vector<int>(n+1);
    for(int i = 0; i < n; i++){
        cin>>v[i];
        for(int j = 0; j < 3; j++)
            p[c[j]][i+1] = p[c[j]][i];
        p[v[i]][i+1]++;
    }
    int ans = 0;
    for(char a: c){
        for(char b: c){
            for(int i = 0; i <= n; i++){
                if(a == b)
                    continue;
                int l = p[a][i];
                int r = p[b][n] - p[b][i];
                ans = max(ans, l + r);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
