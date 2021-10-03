#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll mod = 1e9+7;

int main(){
    int n, m;
        cin>>n>>m;
    vector<vector<char>> v(n, vector<char>(m));
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char c;
            cin>>c;
            if(c == 't')
                ans++;
        }
    }
    cout<<ans<<endl;
}