#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main(){
    //freopen("input.txt", "r", stdin);
    vector<vector<char>> a(8, vector<char>(8));
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin>>a[i][j];
    
    vector<int> p(8);
    ll ans = 0;
    iota(p.begin(), p.end(), 0);
    do{
        bool ok = 1;
        for(int i = 0; i < 8; i++)
            ok &= a[i][p[i]] == '.';
        vector<bool> b(8, 0);
        for(int i = 0; i < 8; i++){
            if(b[i+p[i]])
                ok = 0;
            b[i+p[i]] = 1;
        }
        b = vector<bool>(8, 0);
        for(int i = 0; i < 8; i++){
            if(b[i+7-p[i]])
                ok = 0;
            b[i+7-p[i]] = 1;
        }
        ans += ok;
    }while(next_permutation(p.begin(), p.end()));
    cout<<ans<<endl;
    return 0;
}